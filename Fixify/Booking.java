package Fixify;

/**
 * Demonstration of Class, Object, Constructor, access specifier, method overloading
 * Reg.No.: 2147033
 * Name: Jahid A
 */

import java.util.Date;
import java.util.Scanner;

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
    public boolean validateBooking() throws IllegalArgumentException {
        // boolean isValid = true;
        if (device == null || device.equals("")) {
            // System.out.println("\nDevice cannot be empty");
            // isValid = false;
            throw new IllegalArgumentException("Device cannot be empty");
        }
        if (model == null || model.equals("")) {
            // System.out.println("\nModel cannot be empty");
            // isValid = false;
            throw new IllegalArgumentException("Model cannot be empty");
        }
        if (imeiNumber == null || imeiNumber.equals("")) {
            // System.out.println("\nIMEI Number cannot be empty");
            // isValid = false;
            throw new IllegalArgumentException("IMEI Number cannot be empty");
        }
        if (customerName == null || customerName.equals("")) {
            // System.out.println("\nCustomer Name cannot be empty");
            // isValid = false;
            throw new IllegalArgumentException("Customer Name cannot be empty");
        }
        if (customerPhone == null || customerPhone.equals("")) {
            // System.out.println("\nCustomer Phone cannot be empty");
            // isValid = false;
            throw new IllegalArgumentException("Customer Phone cannot be empty");
        }
        if (customerEmail == null || customerEmail.equals("")) {
            // System.out.println("\nCustomer Email cannot be empty");
            // isValid = false;
            throw new IllegalArgumentException("Customer Email cannot be empty");
        }

        // return isValid;
        return true;

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
        sc.close();
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

        Booking booking1 = new Booking(1); // Constructor

        // Methods
        booking1.takeRepairInfo();

        System.out.println("\nValidating your data...");
        try {

            if (booking1.validateBooking()) {
                booking1.showBooking();
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        } finally {
            System.out.println("\nThank you for using Fixify");
        }

        // if (booking1.validateBooking()) {
        // booking1.showBooking();
        // }

        // Overloading
        // Booking booking2 = new Booking(2, "Jahid");

    }
}