/**
 * 3. Demonstration of inheritance in java
 * Reg: 2147033
 * @author Jahid A
 */

package Fixify;

// Interface
interface PaymentType {
    public static final int CREDIT_CARD = 1;
    public static final int BANK_ACCOUNT = 2;
    public static final int CASH = 3;
    public static final int CHECK = 4;
    public static final int DEBIT_CARD = 5;
    public static final int OTHER = 6;

    public static final String[] PAYMENT_TYPES = { "CREDIT_CARD", "BANK_ACCOUNT", "CASH", "CHECK", "DEBIT_CARD",
            "OTHER" };

    // Interface method
    String showPaymentType();

}

public class Payment implements PaymentType {

    // Payment class variables
    private Booking booking;
    private String amount;
    private String status;
    private int paymentType;

    // PaymentType interface methods implementationßß
    public String showPaymentType() {
        return "Payment Type: " + PAYMENT_TYPES[paymentType - 1];
    }

    Payment(Booking booking, String amount, String status, int paymentType) {
        this.booking = booking;
        this.amount = amount;
        this.status = status;
        this.paymentType = paymentType;
    }

    void printPaymentInfo() {

        System.out.println("\nBooking info\n");
        booking.showBooking();

        System.out.println("\nPayment info\n");
        System.out.println("Amount: " + amount);
        System.out.println("Status: " + status);
        // Accessing PaymentType interface method
        System.out.println(this.showPaymentType());
    }

    public static void main(String[] args) {
        Booking booking1 = new Booking(1);
        booking1.takeRepairInfo();
        Payment payment1 = new Payment(booking1, "100", "Paid", PaymentType.CREDIT_CARD);
        payment1.printPaymentInfo();

        Booking booking2 = new Booking(2);
        booking2.takeRepairInfo();
        Payment payment2 = new Payment(booking2, "100", "Paid", PaymentType.BANK_ACCOUNT);
        payment2.printPaymentInfo();
    }

}
