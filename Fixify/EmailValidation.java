package Fixify;

import java.util.regex.Pattern;

public class EmailValidation implements Runnable {

    String email;

    EmailValidation(String email) {
        this.email = email;
    }

    public boolean validate() {
        try {
            Thread.sleep(5000);
        } catch (Exception e) {
        }
        Pattern pattern = Pattern.compile("^[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,6}$", Pattern.CASE_INSENSITIVE);
        return pattern.matcher(this.email).matches();

    }

    public void run() {
        if (!this.validate()) {
            System.out.println("Invalid Email address");
        } else {
            System.out.println("Valid Email address: Proceed to next step");
        }
    }
}
