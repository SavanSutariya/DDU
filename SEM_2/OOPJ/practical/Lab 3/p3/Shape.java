import java.util.Scanner;
class Circle {
  double radius;

  Circle(double r) {
    radius = r;
  }

  double area() {
    return Math.PI * radius * radius;
  }
}

class Triangle {
  double base, height;

  Triangle(double b, double h) {
    base = b;
    height = h;
  }

  double area() {
    return 0.5 * base * height;
  }
}

class Rectangle {
  double length, width;

  Rectangle(double l, double w) {
    length = l;
    width = w;
  }

  double area() {
    return length * width;
  }
}

class Shape {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int choice;
    double rad, b, h, l, w;

    while (true) {
      System.out.println("1. Area of Circle");
      System.out.println("2. Area of Triangle");
      System.out.println("3. Area of Rectangle");
      System.out.println("4. Exit");
      System.out.print("Enter your choice: ");
      choice = sc.nextInt();

      switch (choice) {
        case 1:
          System.out.print("Enter the radius of the Circle: ");
          rad = sc.nextDouble();
          Circle c = new Circle(rad);
          System.out.println("The area of the Circle is: " + c.area());
          break;
        case 2:
          System.out.print("Enter the base of the Triangle: ");
          b = sc.nextDouble();
          System.out.print("Enter the height of the Triangle: ");
          h = sc.nextDouble();
          Triangle t = new Triangle(b, h);
          System.out.println("The area of the Triangle is: " + t.area());
          break;
        case 3:
          System.out.print("Enter the length of the Rectangle: ");
          l = sc.nextDouble();
          System.out.print("Enter the width of the Rectangle: ");
          w = sc.nextDouble();
          Rectangle r = new Rectangle(l, w);
          System.out.println("The area of the Rectangle is: " + r.area());
          break;
        case 4:
          System.exit(0);
        default:
          System.out.println("Invalid choice");
          break;
      }
    }
  }
}
