package Fixify;

/**
 * Demonstration of Class, Object, Constructor, access specifier, method overloading
 * Reg.No.: 2147033
 * Name: Jahid A
 */

import java.util.Date;
import java.util.Scanner;

// Acesss Specifier:
// Public
// Private
// Protected

public class Booking {
    // Attributes
    // Public Access Specifier
    public int id;
    // Private Access Specifiers
    private String device;
    private String model;
    private String imeiNumber;
    private String customerName;
    private String customerPhone;
    private String customerEmail;
    private Date bookedAt = new Date(); // Current timestamp

    // Default Constructor
    Booking(int id) {
        this.id = id;
    }

    // Parameterized Constructor
    void Booking(int id, String customerName) {
        this.id = id;
        this.customerName = customerName;
    }

    // validate all the inputs
    public boolean validateBooking() {
        boolean isValid = true;
        if (device == null && device.equals("")) {
            System.out.println("\nDevice cannot be empty");
            isValid = false;
        }
        if (model == null && model.equals("")) {
            System.out.println("\nModel cannot be empty");
            isValid = false;
        }
        if (imeiNumber == null && imeiNumber.equals("")) {
            System.out.println("\nIMEI Number cannot be empty");
            isValid = false;
        }
        if (customerName == null && customerName.equals("")) {
            System.out.println("\nCustomer Name cannot be empty");
            isValid = false;
        }
        if (customerPhone == null && customerPhone.equals("")) {
            System.out.println("\nCustomer Phone cannot be empty");
            isValid = false;
        }
        if (customerEmail == null && customerEmail.equals("")) {
            System.out.println("\nCustomer Email cannot be empty");
            isValid = false;
        }
        return isValid;
    }

    // Methods
    // Take input from the user and store it in the object
    public void takeRepairInfo() {
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEnter Repair Information");
        System.out.println("\nIMEI Number: ");
        imeiNumber = sc.nextLine();
        System.out.println("Customer Name: ");
        customerName = sc.nextLine();
        System.out.println("Customer Phone: ");
        customerPhone = sc.nextLine();
        System.out.println("Customer Email: ");
        customerEmail = sc.nextLine();
        System.out.println("Device: ");
        device = sc.nextLine();
        System.out.println("Model: ");
        model = sc.nextLine();
    }

    // Prints all the attributes of the object
    public void showBooking() {
        System.out.println("\nBooking Information");
        System.out.println("\nID: " + id);
        System.out.println("Device: " + device);
        System.out.println("Model: " + model);
        System.out.println("IMEI Number: " + imeiNumber);
        System.out.println("Customer Name: " + customerName);
        System.out.println("Customer Phone: " + customerPhone);
        System.out.println("Customer Email: " + customerEmail);
        System.out.println("Booked At: " + bookedAt);
    }

    public static void main(String[] args) {

        // Class and Object demonstration

        // Booking booking1 = new Booking(1); // Constructor
        System.out.println("Class info" + new Booking(1).getClass());

        // Methods
        // booking1.takeRepairInfo();
        // if (booking1.validateBooking()) {
        // booking1.showBooking();
        // }

        // Overloading
        // Booking booking2 = new Booking(2, "Jahid");

    }
}