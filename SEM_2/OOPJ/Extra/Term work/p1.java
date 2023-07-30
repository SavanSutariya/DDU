import java.util.Scanner;

public class p1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the wattage of the device: ");
        int wattage = input.nextInt();

        System.out.print("Enter the number of usage hours per day: ");
        int usageHours = input.nextInt();

        System.out.print("Enter your electricity rate in paisa per kWh: ");
        double rate = input.nextDouble()/100;

        double wattHours = wattage * usageHours;
        double kWh = wattHours / 1000;
        double costPerDay = kWh * rate;
        double costPerMonth = costPerDay * 30;

        System.out.printf("The estimated cost of using the device is Rs. %.2f per day.%n", costPerDay);
        System.out.printf("The estimated cost of using the device is Rs. %.2f per month.%n", costPerMonth);
        input.close();
    }
}
