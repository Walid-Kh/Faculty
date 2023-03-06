public class Main {
  public static void main(String[] args) {
    IdentityMatrix x = new IdentityMatrix(2, 2);
    int[] arr = {1, 0, 0, 1};
    x.setNumber(arr);
    x.transpose();
    x.print();
  }
}