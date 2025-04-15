public class MainClass {
    public static void main(String[] args) {
        HelperClass helper = new HelperClass();
        helper.printMessage();
    }
}

class HelperClass {
    public void printMessage() {
        System.out.println("Hello from HelperClass!");
    }
}
