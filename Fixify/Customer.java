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
        Customer customer = new Customer("123", "John", "123 Main Street", "123-456-7890", "john.parker@gmail.com");
        customer.showCustomer();
    }

}
