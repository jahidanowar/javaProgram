package Fixify;

public class Customer {

    // Attributes
    private String id;
    private String name;
    private String address;
    private String phone;
    private String email;

    // Constructors
    public Customer(String id, String name, String address, String phone, String email) {
        this.id = id;
        this.name = name;
        this.address = address;
        this.phone = phone;
        this.email = email;
    }

    // Methods
    public void showCustomer() {
        System.out.println("Customer ID: " + this.id);
        System.out.println("Customer Name: " + this.name);
        System.out.println("Customer Address: " + this.address);
        System.out.println("Customer Phone: " + this.phone);
        System.out.println("Customer Email: " + this.email);
    }

    public static void main(String[] args) {
        Customer customer = new Customer("123", "Jahid", "123 Main Street", "123-456-7890", "john.parker@gmail.com");

        // From a here we are outsourcing the operation to a different thread
        UserValidation uv = new UserValidation(customer.name);
        Thread t1 = new Thread(uv, "UserValidation");
        t1.setPriority(Thread.MIN_PRIORITY);

        // Starting another thread for email validation
        EmailValidation ev = new EmailValidation(customer.email);
        Thread t2 = new Thread(ev, "Email Validation");
        t2.setPriority(Thread.MAX_PRIORITY);

        t1.start();
        t2.start();

        customer.showCustomer();
    }

}
