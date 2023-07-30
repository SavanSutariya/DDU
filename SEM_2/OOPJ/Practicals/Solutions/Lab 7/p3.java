import java.util.Scanner;
class NoMatchException extends Exception {
    public NoMatchException(String message) {
        super(message);
    }
}

class p3 {
    public static void main(String[] args) {
        String str;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        str = sc.nextLine();
        try {
            if (!str.equals("Object Oriented Programming with JAVA")) {
                throw new NoMatchException("String does not match");
            }
        } catch (NoMatchException e) {
            System.out.println("Caught exception: " + e.getMessage());
        }
    }
}
