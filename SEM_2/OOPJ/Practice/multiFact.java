import java.util.Scanner;

public class multiFact implements Runnable {
    private int number;

    public multiFact(int number) {
        this.number = number;
    }

    @Override
    public void run() {
        long factorial = calculateFactorial(number);
        System.out.println("Factorial of " + number + " is: " + factorial);
    }

    private long calculateFactorial(int n) {
        long factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
        return factorial;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int number = scanner.nextInt();

        for (int i = 1; i <= number; i++) {
            Thread thread = new Thread(new multiFact(i));
            thread.start();
        }
    }
}
