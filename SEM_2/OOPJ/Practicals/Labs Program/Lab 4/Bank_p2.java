// W.A.P for the inheritance and override displayInfo() method and use super keyword to inherit parent
// class features. 
// Account : CustName, Acno, type, Branch, getCustInfo(), displayInfo()
// Savings : Amount, Rate, Year, getSavingInfo(), calIntAmt(), displayInfo()
// FixedDiposite : Amount, Rate, Year, getFDInfo(), calIntAmt(), displayInfo()

// For savings account,
// Rate = 3.5 (fix)
// Calculate interest = (amount* rate * year)/100
// For Fixed Deposit,
// Years || Rate
// <=2 || 6.5
// >2 and <=5   || 7.5
// >5 and <=10 || 8.5
// >10 || 9
// Calculate interest = (amount* rate * year)/100

// Path: Bank_p2.java

// A class to represent a bank account
class Account {
    private String custName;
    private int acno;
    private String type;
    private String branch;

    // Constructor to initialize the custName, acno, type, and branch fields
    public Account(String custName, int acno, String type, String branch) {
        this.custName = custName;
        this.acno = acno;
        this.type = type;
        this.branch = branch;
    }

    // Getter method for the custName field
    public String getCustName() {
        return this.custName;
    }

    // Getter method for the acno field
    public int getAcno() {
        return this.acno;
    }

    // Getter method for the type field
    public String getType() {
        return this.type;
    }

    // Getter method for the branch field
    public String getBranch() {
        return this.branch;
    }

    // Method to display the account information
    public void displayInfo() {
        System.out.println("Account Information:");
        System.out.println("Customer Name: " + this.getCustName());
        System.out.println("Account Number: " + this.getAcno());
        System.out.println("Account Type: " + this.getType());
        System.out.println("Branch: " + this.getBranch());
    }
}

// A class to represent a savings account, which inherits from Account
class Savings extends Account {
    private double amount;
    private double rate;
    private int year;

    // Constructor to initialize the custName, acno, type, branch, amount, rate, and year fields
    public Savings(String custName, int acno, String type, String branch, double amount, double rate, int year) {
        super(custName, acno, type, branch);
        this.amount = amount;
        this.rate = rate;
        this.year = year;
    }

    // Getter method for the amount field
    public double getAmount() {
        return this.amount;
    }

    // Getter method for the rate field
    public double getRate() {
        return this.rate;
    }

    // Getter method for the year field
    public int getYear() {
        return this.year;
    }

    // Method to display the savings account information
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Amount: " + this.getAmount());
        System.out.println("Rate: " + this.getRate());
        System.out.println("Year: " + this.getYear());
    }

    // Method to calculate the interest amount
    public double calIntAmt() {
        return (this.getAmount() * this.getRate() * this.getYear()) / 100;
    }
}

// A class to represent a fixed deposit account, which inherits from Account

class FixedDeposit extends Account {
    private double amount;
    private double rate;
    private int year;

    // Constructor to initialize the custName, acno, type, branch, amount, rate, and year fields
    public FixedDeposit(String custName, int acno, String type, String branch, double amount, double rate, int year) {
        super(custName, acno, type, branch);
        this.amount = amount;
        this.rate = rate;
        this.year = year;
    }

    // Getter method for the amount field
    public double getAmount() {
        return this.amount;
    }

    // Getter method for the rate field
    public double getRate() {
        return this.rate;
    }

    // Getter method for the year field
    public int getYear() {
        return this.year;
    }

    // Method to display the fixed deposit account information
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Amount: " + this.getAmount());
        System.out.println("Rate: " + this.getRate());
        System.out.println("Year: " + this.getYear());
    }

    // Method to calculate the interest amount
    public double calIntAmt() {
        if (this.getYear() <= 2) {
            this.rate = 6.5;
        } else if (this.getYear() > 2 && this.getYear() <= 5) {
            this.rate = 7.5;
        } else if (this.getYear() > 5 && this.getYear() <= 10) {
            this.rate = 8.5;
        } else {
            this.rate = 9;
        }
        return (this.getAmount() * this.getRate() * this.getYear()) / 100;
    }
}

// A class to test the Account, Savings, and FixedDeposit classes
public class Bank_p2 {
    public static void main(String[] args) {
        // Create a savings account
        Savings s = new Savings("John", 1234, "Savings", "Chennai", 10000, 3.5, 2);
        // Display the savings account information
        s.displayInfo();
        // Calculate and display the interest amount
        System.out.println("Interest Amount: " + s.calIntAmt());

        // Create a fixed deposit account
        FixedDeposit f = new FixedDeposit("Mary", 5678, "Fixed Deposit", "Chennai", 10000, 6.5, 2);
        // Display the fixed deposit account information
        f.displayInfo();
        // Calculate and display the interest amount
        System.out.println("Interest Amount: " + f.calIntAmt());
    }
}

// Output:
// Account Information:
// Customer Name: John
// Account Number: 1234
// Account Type: Savings
// Branch: Chennai
// Amount: 10000.0
// Rate: 3.5
// Year: 2
// Interest Amount: 700.0
// Account Information:
// Customer Name: Mary
// Account Number: 5678
// Account Type: Fixed Deposit
// Branch: Chennai
// Amount: 10000.0
// Rate: 6.5
// Year: 2
// Interest Amount: 1300.0
