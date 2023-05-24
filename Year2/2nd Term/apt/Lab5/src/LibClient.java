import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class LibClient {
  public static final int BORROW_PORT = 6666;
  public static final int RETURN_PORT = 6667;

  public static void main(String[] args) throws java.net.UnknownHostException, java.io.IOException {
    Scanner scanner = new Scanner(System.in);
    String clientName = scanner.nextLine();

    Socket borrowSocket = new Socket("localhost", BORROW_PORT);
    Socket returnSocket = new Socket("localhost", RETURN_PORT);
    PrintWriter borrowPrintWriter = new PrintWriter(borrowSocket.getOutputStream(), true);
    PrintWriter returnPrintWriter = new PrintWriter(returnSocket.getOutputStream(), true);
    BufferedReader borrowBufferReader = new BufferedReader(new InputStreamReader(borrowSocket.getInputStream()));
    BufferedReader returnBufferReader = new BufferedReader(new InputStreamReader(returnSocket.getInputStream()));

    borrowPrintWriter.println(clientName);
    returnPrintWriter.println(clientName);
    String command = "";
    while (true)
    {
      System.out.println("enter (1)borrow or (2)return a book and the isbn of that book");
      if ((command = scanner.nextLine()) == null)
          break;
      var arguments = command.split(" ");
      if (arguments[0].equals("1"))
      {
        // borrow client logic
        borrowPrintWriter.println(arguments[1]);
        System.out.println("Server: " + borrowBufferReader.readLine());
      }
      else if (arguments[0].equals("2"))
      {
        // return client logic
        returnPrintWriter.println(arguments[1]);
        System.out.println("Server: " + returnBufferReader.readLine());
      }
    }
    borrowPrintWriter.close();
    returnPrintWriter.close();
    borrowBufferReader.close();
    returnPrintWriter.close();
    borrowSocket.close();
    returnSocket.close();
  }


}
