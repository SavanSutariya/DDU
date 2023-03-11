// A class to represent a vehicle
class Vehicle {
    private String make
    // Getter method for the make field
    public String getMake() {
        return this.make;
    }
}

// A class to represent a car, which inherits from Vehicle
class Car extends Vehicle {
    private String model;

    // Constructor to initialize the make and model fields
    public Car(String make, String model) {
        super(make);
        this.model = model;
    }

    // Getter method for the model field
    public String getModel() {
        return this.model;
    }
}

// A class to represent a sports car, which inherits from Car
class SportsCar extends Car {
    private int topSpeed;

    // Constructor to initialize the make, model, and topSpeed fields
    public SportsCar(String make, String model, int topSpeed) {
        super(make, model);
        this.topSpeed = topSpeed;
    }

    // Getter method for the topSpeed field
    public int getTopSpeed() {
        return this.topSpeed;
    }
}

// Main class to demonstrate multilevel inheritance and use of the super keyword
public class InheritanceDemo_p1 {
    public static void main(String[] args) {
        // Create a Vehicle object
        Vehicle vehicle = new Vehicle("Honda");
        System.out.println("Vehicle:");
        System.out.println("Make: " + vehicle.getMake());

        // Create a Car object
        Car car = new Car("Toyota", "Corolla");
        System.out.println("Car:");
        System.out.println("Make: " + car.getMake());
        System.out.println("Model: " + car.getModel());

        // Create a SportsCar object
        SportsCar sportsCar = new SportsCar("Ferrari", "458 Italia", 325);
        System.out.println("Sports Car:");
        System.out.println("Make: " + sportsCar.getMake());
        System.out.println("Model: " + sportsCar.getModel());
        System.out.println("Top Speed: " + sportsCar.getTopSpeed() + " km/h");
    }
}
