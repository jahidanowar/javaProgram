public class Doctor {

    public int licenseNumber;
    public String name;
    public String specialty;
    public String address;
    public String phoneNumber;

    public Doctor(int licenseNumber, String name, String specialty, String address, String phoneNumber) {
        this.licenseNumber = licenseNumber;
        this.name = name;
        this.specialty = specialty;
        this.address = address;
        this.phoneNumber = phoneNumber;

    }

    public void consult() {
        System.out.println("Doctor " + name + " is consulting");

    }

    public static void prescribe() {
        System.out.println("Doctor " + " is prescribing");

    }

    public static void main(String[] args) {
        Doctor doctorJohn = new Doctor(12345, "John", "Cardiology", "123 Main St.", "555-555-5555");
        Doctor doctorAlice = new Doctor(54321, "Alice", "Dermatology", "456 Main St.", "555-555-5555");

        doctorJohn.consult();
        doctorAlice.consult();

    }

}

// X ^ Y
