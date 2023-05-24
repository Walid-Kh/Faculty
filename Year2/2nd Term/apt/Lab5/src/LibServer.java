import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class LibServer {
  private static Library library;
  public static final int BORROW_PORT = 6666;
  public static final int RETURN_PORT = 6667;

  public static void main(String[] args) {
    library = new Library();

    new Thread() {
      public void run() {
        try {
          ServerSocket bs = new ServerSocket(BORROW_PORT);
          while (true) {
            (new LibraryReceptionist(bs.accept())).start();
          }
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
    }.start();
    new Thread()
    {
      public void run()
      {
        try {
          ServerSocket bs = new ServerSocket(RETURN_PORT);
          while (true) {
            (new LibraryReceptionist(bs.accept())).start();
          }
        }catch (IOException e)
        {
          e.printStackTrace();
        }
      }
    }.start();
  }

  private static class LibraryReceptionist extends Thread {
    int isbn;
    String clientName;
    Socket socket;

    public LibraryReceptionist(Socket socket) {
      this.socket = socket;
    }

    public void run() {
      try {
        BufferedReader bf = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
        PrintWriter pw = new PrintWriter(this.socket.getOutputStream(), true);
        clientName = bf.readLine();
        while (true) {
          String message;
          if ((message = bf.readLine()) == null || message.equals("."))
            break;
          isbn = Integer.parseInt(message);
          String result = null;
          synchronized (library) {
            if (this.socket.getLocalPort() == BORROW_PORT) {
              result = library.borrow(isbn, clientName);
            } else if (this.socket.getLocalPort() == RETURN_PORT) {
              result = library.returnBack(isbn, clientName);
            }
          }
          pw.println(result);
          library.print();
        }
        bf.close();
        pw.close();
      } catch (IOException e) {
        e.printStackTrace();
      }

    }

  }
}
