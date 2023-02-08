// Write a Java program which calculates the area of Circle, Triangle and Rectangle. Create three
// different classes which call the Constructors of Rectangle, Triangle and Circle by passing parameters
// to the constructors.
// Create a main method class named Shape which provides the user a menu through which the user
// can calculate the area of the respected shape using the area() method of that class.

import java.util.Scanner;
public class Shape {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;
        System.out.println("Enter the shape for which you want to calculate the area");
        System.out.println("1. Circle");
        System.out.println("2. Triangle");
        System.out.println("3. Rectangle");
        choice = sc.nextInt();
        switch (choice) {
            case 1:
                System.out.println("Enter the radius of the circle");
                double radius = sc.nextDouble();
                Circle obj = new Circle(radius);
                System.out.println("The area of the circle is " + obj.area());
                break;
            case 2:
                System.out.println("Enter the base of the triangle");
                double base = sc.nextDouble();
                System.out.println("Enter the height of the triangle");
                double height = sc.nextDouble();
                Triangle obj1 = new Triangle(base, height);
                System.out.println("The area of the triangle is " + obj1.area());
                break;
            case 3:
                System.out.println("Enter the length of the rectangle");
                double length = sc.nextDouble();
                System.out.println("Enter the breadth of the rectangle");
                double breadth = sc.nextDouble();
                Rectangle obj2 = new Rectangle(length, breadth);
                System.out.println("The area of the rectangle is " + obj2.area());
                break;
            default:
                System.out.println("Invalid choice");
        }
    }
}
class Circle {
    double radius;
    Circle(double radius) {
        this.radius = radius;
    }
    double area() {
        return 3.14 * radius * radius;
    }
}
class Triangle {
    double base, height;
    Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }
    double area() {
        return 0.5 * base * height;
    }
}
class Rectangle {
    double length, breadth;
    Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }
    double area() {
        return length * breadth;
    }
}