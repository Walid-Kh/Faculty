public class Matrix implements Addable<Matrix> {
  protected int M, N;

  protected int[][] mat;

  public Matrix(int n, int m) {
    this.M = m;
    this.N = n;
    this.mat = new int[n][m];
  }

  public void setNumbers(int[] num) {
    if (num.length != this.N * this.M)
      return;
    int index = 0;
    for (int i = 0; i < this.N; i++) {
      for (int j = 0; j < this.M; j++) {
        this.mat[i][j] = num[index++];
      }
    }
  }

  public void print() {
    for (int i = 0; i < this.N; i++) {
      for (int j = 0; j < this.M; j++) {
        System.out.print(this.mat[i][j] + " ");
      }
      System.out.print("\n");
    }
  }

  public void transpose() {
    int rows = this.M;
    int cols = this.N;
    int[][] newMat = new int[rows][cols];
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        newMat[i][j] = this.mat[j][i];
      }
    }
    this.mat = newMat;
    this.N = rows;
    this.M = cols;
  }

  @Override
  public Matrix Add(Matrix x) {
    if (!(x.N == this.N && x.M == this.M))
      throw new Error("Dimensions are incorrect");
    int index = 0;
    int[] mat = new int[this.M * this.N];
    for (int i = 0; i < this.N; i++) {
      for (int j = 0; j < this.M; j++) {
        mat[index++] = this.mat[i][j] + x.mat[i][j];
      }
    }
    Matrix res = new Matrix(this.N, this.M);
    res.setNumbers(mat);
    return res;
  }

}
