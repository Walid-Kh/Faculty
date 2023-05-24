import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Library {
  private final Hashtable<Integer, Book> Books;

  public Library() {
    Books = readBooksFromFile();
  }

  public String borrow(int isbn, String clientName) {
    String result;
    var book = Books.get(isbn);
    if (book == null)
      result = "Error: Book doesn't exist";
    else if (book.borrowed) {
      result = "Error: Book is borrowed by someone";
    } else {
      book.borrowed = true;
      book.borrower = clientName;
      result = "Success: Book Borrowed";
    }
    return result;
  }

  public String returnBack(int isbn, String clientName) {
    var book = Books.get(isbn);
    if (book == null)
      return "Error: Book doesn't exist";
    else if (!book.borrowed)
      return "Error: Book isn't Borrowed";
    else if (book.borrower.equals(""))
      return "Error: The Book isn't borrowed";
    else if (!book.borrower.equals(clientName))
      return "Error: You haven't borrowed the book";
    book.borrower = "";
    book.borrowed = false;
    return "Success: the Book has been returned";
  }

  public void print() {
    var it = Books.elements();
    while (it.hasMoreElements()) {
      var book = it.nextElement();
      System.out.println(book.isbn + " " +
              (!book.borrowed ? "Not Borrowed" : book.borrower));
    }
  }

  private static Hashtable<Integer, Book> readBooksFromFile() {
    Hashtable<Integer, Book> result = new Hashtable<>();
    try {
      File booksFile = new File("Books.txt");
      Scanner scanner = new Scanner(booksFile);
      while (scanner.hasNextLine()) {
        String[] book = scanner.nextLine().split(" ");
        Book x = new Book();
        x.isbn = Integer.parseInt(book[0]);
        x.title = book[1];
        x.author = book[2];
        x.borrowed = false;
        x.borrower = "";
        result.put(x.isbn, x);
      }
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
    return result;
  }


}
