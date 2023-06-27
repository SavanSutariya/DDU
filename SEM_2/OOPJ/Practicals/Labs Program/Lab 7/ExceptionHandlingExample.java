import java.util.Scanner;
public class ExceptionHandlingExample {
    public static void main(String[] args) {
        int x,y;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two numbers: ");
        x = sc.nextInt();
        y = sc.nextInt();
        try {
            // Divide by zero exception
            int z = x / y;

            // String index out of bounds exception
            String str = "Hello";
            char c = str.charAt(10);
        } catch (ArithmeticException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (StringIndexOutOfBoundsException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            System.out.println("Finally block executed.");
        }
    }
}
