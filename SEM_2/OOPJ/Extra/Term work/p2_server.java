import java.io.*;
import java.net.*;

public class p2_server {
    public static void main(String[] args) throws IOException {
        // create a new ServerSocket on port 5500
        ServerSocket serverSocket = new ServerSocket(5500);
        // wait for a client to connect and accept the connection
        Socket socket = serverSocket.accept();
        // create input and output streams for communication with the client
        DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());
        DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());
        // read an integer value from the client
        int value = dataInputStream.readInt();
        // process the value (here it is being squared)
        System.out.println("Received "+value);
        value = value * value;
        System.out.println("Sending "+value);
        // send the processed value back to the client
        dataOutputStream.writeInt(value);
        // close the socket and serverSocket
        socket.close();
        serverSocket.close();
    }
}
