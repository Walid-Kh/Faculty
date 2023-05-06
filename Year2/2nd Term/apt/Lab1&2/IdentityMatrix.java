public class IdentityMatrix extends Matrix {

  public IdentityMatrix(int n, int m) {
    super(n, m);
    if (n != m)
      throw new Error("Identity Must be a Square Matrix");
  }

  @Override
  public void setNumber(int[] num) {
    int dimensions = (int) Math.sqrt(num.length);
    if (M == N && dimensions * dimensions == num.length) {
      int index = 0;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (num[index] == 1 && i == j || i != j && num[index] == 0) {
            mat[i][j] = num[index++];
          } else {
            throw new Error("Doesn't meet Identity Matrix Definition ");
          }
        }
      }
    }
  }

  @Override
  public void transpose() {
    return;
  }
}
