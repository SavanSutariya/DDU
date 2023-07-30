import java.io.*;
import java.net.*;
import java.util.Scanner;

public class p2_client {
    public static void main(String[] args) throws IOException {
        // create a scanner object for reading input from the user
        Scanner scanner = new Scanner(System.in);
        // create a new socket to connect to the server at "localhost" on port 5500
        Socket socket = new Socket("localhost", 5500);
        // create input and output streams for communication with the server
        DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());
        DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());
        // read an integer value from the user
        System.out.println("Enter a value: ");
        int value = scanner.nextInt();
        // send the value to the server
        dataOutputStream.writeInt(value);
        // receive the processed value from the server
        int result = dataInputStream.readInt();
        // print the result
        System.out.println("Result: " + result);
        // close the socket
        socket.close();
    }
}
