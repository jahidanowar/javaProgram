/**
 * 3. Demonstration of this and super in java
 * Reg: 2147033
 * @author Jahid A
 */
package Fixify;

public class Device extends Category {
    String name;

    public Device(String category, String name) {
        // Call super constructor
        // super() refers to constructor of imidiate extended class
        super(category);
        this.name = name;
    }

    public void showDeviceInfo() {
        // Using super to call method of parent class
        System.out.println("Category name: " + super.getName());
        // Using this to access instance variables
        System.out.println("Device name: " + this.name);
    }

    public static void main(String[] args) {
        // Create an object of Device class
        Device device = new Device("Mobile Phones", "iPhone");
        // Call method of Device class
        device.showDeviceInfo();
    }

}
