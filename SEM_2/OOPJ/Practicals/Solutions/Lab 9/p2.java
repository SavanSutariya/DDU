import java.util.LinkedList;
import java.util.ListIterator;

public class p2 {

    public static void main(String[] args) {
        // Create a new LinkedList
        LinkedList<String> linkedList = new LinkedList<String>();

        // Insert elements at the beginning of the LinkedList
        linkedList.addFirst("apple");
        linkedList.addFirst("banana");
        linkedList.addFirst("orange");
        System.out.println("LinkedList after adding elements at the beginning: " + linkedList);

        // Insert elements at the end of the LinkedList
        linkedList.addLast("pear");
        linkedList.addLast("grape");
        linkedList.addLast("pineapple");
        System.out.println("LinkedList after adding elements at the end: " + linkedList);

        // Delete the first element of the LinkedList
        linkedList.removeFirst();
        System.out.println("LinkedList after deleting the first element: " + linkedList);

        // Delete the last element of the LinkedList
        linkedList.removeLast();
        System.out.println("LinkedList after deleting the last element: " + linkedList);

        // Update the value of an element at a specific index
        linkedList.set(1, "cherry");
        System.out.println("LinkedList after updating the value of an element at index 1: " + linkedList);

        // Remove an element from a specific index
        linkedList.remove(2);
        System.out.println("LinkedList after removing an element from index 2: " + linkedList);

        // Display the LinkedList using an iterator
        ListIterator<String> iterator = linkedList.listIterator();
        System.out.print("LinkedList using iterator: ");
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + " ");
        }
    }
}
