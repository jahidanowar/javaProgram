package Bank;

import java.util.ArrayList;
import java.io.*;

class Account {
    static int count = 1;
    int account_number = 0;
    int balance = 0;

    Account() {
        account_number = count++;
    }

    void display_account_details() {
        System.out.println("Account no.: " + account_number);
        System.out.println("Balance: " + balance);
    }

    public String deposit_money(int amount) {
        balance = balance + amount;
        return amount + " deposited to account no. " + account_number;
    }

    public String withdraw_money(int amount) {
        if (balance >= amount) {
            balance = balance - amount;
            return amount + " withdrawn from account no. " + account_number;
        }
        return "Insufficient balance";
    }

    public String display_balance() {
        return "Balance for account no. " + account_number + " is " + balance;
    }

    public void transact(String type, int amount) {
        if (type == "deposit") {
            this.deposit_money(amount);
        } else if (type == "withdrawal") {
            this.withdraw_money(amount);
        }
    }

    static Account search(ArrayList<Account> db, int account_number) {
        for (int i = 0; i < db.size(); i++) {
            if (db.get(i).account_number == account_number) {
                return db.get(i);
            }
        }
        return null;
    }

    static void writeLineToFile(String line) {
        try {
            // FileOutputStream fos = new FileOutputStream("accounts.txt", true);
            FileWriter fw = new FileWriter("accounts.txt", true);
            fw.write(line + "\n");
            fw.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }

    static int total_balance(ArrayList<Account> db) {
        int total = 0;
        for (int i = 0; i < db.size(); i++) {
            total = total + db.get(i).balance;
        }
        return total;
    }

    public static void main(String args[]) {
        ArrayList<Account> accounts = new ArrayList<Account>();
        // Read from file
        String file_path = args[0];
        try {
            FileReader fr = new FileReader(file_path);
            // Read each line of the file into the line variable
            BufferedReader br = new BufferedReader(fr);
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
                String[] tokens = line.split(" ");

                Account matched_account;

                switch (tokens[0]) {
                    case "create_account":
                        Account a = new Account();
                        accounts.add(a);
                        // Write to file
                        writeLineToFile("New account created with account no. " + a.account_number);
                        break;
                    case "deposit":
                        matched_account = search(accounts, Integer.parseInt(tokens[1]));
                        if (matched_account != null) {
                            writeLineToFile(matched_account.deposit_money(Integer.parseInt(tokens[2])));
                        } else {
                            writeLineToFile("Account not found");
                        }
                        break;
                    case "withdraw":
                        matched_account = search(accounts, Integer.parseInt(tokens[1]));
                        if (matched_account != null) {
                            writeLineToFile(matched_account.withdraw_money(Integer.parseInt(tokens[2])));
                        } else {
                            writeLineToFile("Account not found");
                        }
                        break;
                    case "display_bank_balance":
                        matched_account = search(accounts, Integer.parseInt(tokens[1]));
                        if (matched_account != null) {
                            writeLineToFile(matched_account.display_balance());
                        } else {
                            writeLineToFile("Account not found");
                        }
                        break;
                    case "total_balance":
                        writeLineToFile("Total balance in bank is " + total_balance(accounts));
                        break;
                    default:
                        writeLineToFile("Invalid command");
                        break;
                }
            }
            // Closing opened file and buffered reader
            fr.close();
            br.close();

        } catch (IOException e) {
            System.out.println("File not found");
        }
    }
}
