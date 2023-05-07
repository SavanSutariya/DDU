import java.util.HashSet;
import java.util.Iterator;

public class p3 {

    public static void main(String[] args) {
        // Create a new HashSet
        HashSet<String> hashSet = new HashSet<String>();

        // Insert elements into the HashSet
        hashSet.add("apple");
        hashSet.add("banana");
        hashSet.add("orange");
        System.out.println("HashSet after adding elements: " + hashSet);

        // Update an element in the HashSet
        hashSet.remove("banana");
        hashSet.add("cherry");
        System.out.println("HashSet after updating an element: " + hashSet);

        // Delete an element from the HashSet
        hashSet.remove("orange");
        System.out.println("HashSet after deleting an element: " + hashSet);

        // Display the HashSet using an iterator
        Iterator<String> iterator = hashSet.iterator();
        System.out.print("HashSet using iterator: ");
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + " ");
        }
    }
}
