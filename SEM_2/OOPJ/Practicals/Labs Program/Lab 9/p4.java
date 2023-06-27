import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class p4 {

    public static void main(String[] args) {
        // Create a new HashMap
        HashMap<String, Integer> hashMap = new HashMap<String, Integer>();

        // Insert elements into the HashMap
        hashMap.put("apple", 1);
        hashMap.put("banana", 2);
        hashMap.put("orange", 3);
        System.out.println("HashMap after adding elements: " + hashMap);

        // Update an element in the HashMap
        hashMap.put("banana", 4);
        System.out.println("HashMap after updating an element: " + hashMap);

        // Delete an element from the HashMap
        hashMap.remove("orange");
        System.out.println("HashMap after deleting an element: " + hashMap);

        // Display the HashMap using an iterator
        Iterator<Map.Entry<String, Integer>> iterator = hashMap.entrySet().iterator();
        System.out.print("HashMap using iterator: ");
        while (iterator.hasNext()) {
            Map.Entry<String, Integer> entry = iterator.next();
            System.out.print(entry.getKey() + "=" + entry.getValue() + " ");
        }
    }
}
