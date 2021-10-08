package Static;

/* 
    Demonstration of static methods, static variables, and static block.
    Reg.No.: 2147033 
    Name: Jahid A
*/

public class User {

    // Static variables
    static int id;
    // Static block is executed before the constructor
    static {
        id = 25560;
        System.out.println("Static block called");
        System.out.println("id = " + id);
    }

    User() {
        System.out.println("User Contstructor called");
    }

    // Static method
    static void printId() {
        System.out.println("id from static method = " + id);
    }

    public static void main(String[] args) {
        // Static variables are accessible without creating an object
        System.out.println("id from variable = " + id);
        printId();
    }

}
