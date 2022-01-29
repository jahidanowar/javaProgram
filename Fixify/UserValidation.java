package Fixify;

public class UserValidation implements Runnable {

    String[] blockedUsers = { "jahid", "john", "doe", "jimmy", "foxy", "wolfy", "beary" };
    String name;

    UserValidation(String name) {
        this.name = name;
    }

    public void showBlockedUser() {
        for (int i = 0; i < this.blockedUsers.length; i++) {
            System.out.println(i + 1 + ": " + this.blockedUsers[i]);
        }
    }

    public boolean isBlocked() {
        try {
            Thread.sleep(5000);
        } catch (Exception e) {
        }

        boolean flag = false;
        for (int i = 0; i < this.blockedUsers.length; i++) {
            if (this.name.toLowerCase() == this.blockedUsers[i]) {
                flag = true;
                return flag;
            }
        }
        return flag;
    }

    public void run() {
        if (this.isBlocked()) {
            System.out.println("Sorry user can not create account for the violation of the rules");
        } else {
            System.out.println("User is not blocked");
        }
    }
}
