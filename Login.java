public class Login {

    String username;
    String password;

    public Login(String username, String password) {
        this.username = username;
        this.password = password;
        System.out.println("I am from Consteructor");
    }

    public void showLoginInfo() {
        System.out.println("Username: " + username);
        System.out.println("Password: " + password);
    }

    public static void main(String[] args) {

        // Login parasntLogin = new Login('');

        Login loginObject = new Login("admin", "password");

        loginObject.showLoginInfo();
    }

}