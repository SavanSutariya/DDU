import java.util.Scanner;
class ArithmeticIntOp{
			int result;
			ArithmeticIntOp(){
					result = 0;
			}
			void calculate(int a, int b, char op){
				if(op=='+')
					result = a + b;
				else if(op=='-')
					result = a - b;
				else if(op=='/')
					result = a / b;
				else if(op=='*')
					result = a * b;
			}
			int getArithmeticIntOpResult(){
					return result;
			}
}
class RelationalOp{
			boolean result;
			RelationalOp(){
					result = false;
			}
			void calculate(int a, int b, String op){
				switch(op) {
					case "==":
					  result = (a == b);
					  break;
					case "!=":
					  result = (a != b);
					  break;
					case ">":
					  result = (a > b);
					  break;
					case "<":
					  result = (a < b);
					  break;
					default:
					  System.out.println("Invalid operator");
					  break;
				}
			}
			boolean getRelationalOpResult(){
					return result;
			}
}
class BitwiseOp{
			int result;
			BitwiseOp(){
					result = 0;
			}
			void calculate(int a, int b, char op){
				if(op=='|')
					result = (a | b);
				else if(op=='&')
					result = (a & b);
				else if(op=='^')
					result = (a ^ b);
			}
			int getBitwiseOpResult(){
					return result;
			}
}
public class Operator{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		ArithmeticIntOp ao = new ArithmeticIntOp();
		RelationalOp ro = new RelationalOp();
		BitwiseOp bo = new BitwiseOp();
		int n;
		do{
			System.out.println("\n1.Arithmetic\n2.Relational\n3.Bitwise\n4.Exit\nChoose:");
			n = in.nextInt();
			switch(n)
			{
				case 1:
					System.out.print("Addition(+)\nSubtract(-)\nDivide(/)\nMultiply(*)\nChoose:");
					char c = in.next().charAt(0);
					ao.calculate(10,20,c);
					int Result = ao.getArithmeticIntOpResult();
					System.out.println("Result: " + Result);
					break;
				case 2:
					System.out.print("Compare(==)\nNot Equal(!=)\nGreater Than(>)\nLess Than(<)\nChoose:");
					String c1 = in.next();
					ro.calculate(10,20,c1);
					boolean Result1 = ro.getRelationalOpResult();
					System.out.println("Result: " + Result1);
					break;
				case 3:
					System.out.print("OR(|)\nAND(&)\nXOR(^)\nChoose:");
					char c2 = in.next().charAt(0);
					bo.calculate(10,20,c2);
					int Result2 = bo.getBitwiseOpResult();
					System.out.println("Result: " + Result2);
					break;
				case 4:
					System.out.println("Bye....");
					break;
				default:
					System.out.println("Invalid input....");
					break;
			}
		}while(n!=4);
	}
}