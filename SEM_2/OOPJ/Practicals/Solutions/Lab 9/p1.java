import java.util.ArrayList;
import java.util.Iterator;

public class p1 {
    public static void main(String[] args) {
        // Create an ArrayList of strings
        ArrayList<String> fruits = new ArrayList<String>();
        // Add elements to the ArrayList
        fruits.add("apple");
        fruits.add("banana");
        fruits.add("orange");
        fruits.add("grape");
        // Print the ArrayList
        System.out.println("ArrayList: " + fruits);
        // Update an element in the ArrayList
        fruits.set(1, "kiwi");
        // Print the ArrayList after update
        System.out.println("ArrayList after update: " + fruits);
        // Delete an element from the ArrayList
        fruits.remove(2);
        // Print the ArrayList after delete
        System.out.println("ArrayList after delete: " + fruits);
        // Convert the ArrayList to an array
        String[] fruitsArray = fruits.toArray(new String[0]);
        // Print the array
        System.out.println("Array: ");
        for (String fruit : fruitsArray) {
            System.out.println(fruit);
        }
        // Display the ArrayList using iterator()
        System.out.println("ArrayList using iterator(): ");
        Iterator<String> iterator = fruits.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }
    }
}
