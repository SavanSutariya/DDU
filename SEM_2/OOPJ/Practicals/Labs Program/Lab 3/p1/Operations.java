import java.util.Scanner;
public class Operations {
    // main method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b; // operands
        char op; // operator
        String op1; // operator for relational and bitwise operations
        System.out.println("Enter the first number");
        a = sc.nextInt();
        System.out.println("Enter the second number");
        b = sc.nextInt();
        System.out.println("Enter the Arithmatic operation to be performed");
        op = sc.next().charAt(0);
        ArithmeticIntOp obj = new ArithmeticIntOp(); // object of ArithmeticIntOp class
        obj.calculate(a, b, op);
        System.out.println("The result is " + obj.getArithmeticIntOpResult());
        System.out.println("Enter the Relational operation to be performed");
        op1 = sc.next();
        RelationalOp obj1 = new RelationalOp(); // object of RelationalOp class
        obj1.calculate(a, b, op1);
        System.out.println("The result is " + obj1.getRelationalOpResult());
        System.out.println("Enter the Bitwise operation to be performed");
        op1 = sc.next();
        BitwiseOp obj2 = new BitwiseOp(); // object of BitwiseOp class
        obj2.calculate(a, b, op1);
        System.out.println("The result is " + obj2.getBitwiseOpResult());
    }
}
class ArithmeticIntOp {
    int result;
    ArithmeticIntOp() {
        result = 0;
    }
    int getArithmeticIntOpResult() {
        return result;
    }
    void calculate(int a, int b, char op) {
        switch (op) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            default:
                System.out.println("Invalid operation");
        }
    }
}
class RelationalOp {
    boolean result;
    RelationalOp() {
        result = false;
    }
    boolean getRelationalOpResult() {
        return result;
    }
    void calculate(int a, int b, String op) {
        switch (op) {
            case "==":
                result = a == b;
                break;
            case "!=":
                result = a != b;
                break;
            case ">":
                result = a > b;
                break;
            case "<":
                result = a < b;
                break;
            case ">=":
                result = a >= b;
                break;
            case "<=":
                result = a <= b;
                break;
            default:
                System.out.println("Invalid operation");
        }
    }
}
class BitwiseOp {
    int result;
    BitwiseOp() {
        result = 0;
    }
    int getBitwiseOpResult() {
        return result;
    }
    void calculate(int a, int b, String op) {
        switch (op) {
            case "&":
                result = a & b;
                break;
            case "|":
                result = a | b;
                break;
            case "^":
                result = a ^ b;
                break;
            case "~":
                result = ~a;
                break;
            case "<<":
                result = a << b;
                break;
            case ">>":
                result = a >> b;
                break;
            default:
                System.out.println("Invalid operation");
        }
    }
}

// Output:

// Enter the first number
// 10
// Enter the second number
// 20
// Enter the operation to be performed
// +
// The result is 30
// Enter the operation to be performed
// ==
// The result is false
// Enter the operation to be performed
// &
// The result is 0
