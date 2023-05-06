import mpi.MPI;

import java.io.File;
import java.io.FileNotFoundException;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
  private static ArrayList<Integer> fileToArrayList(String filePath) {
    ArrayList<Integer> res = new ArrayList<>();
    try {
      File file = new File(filePath);
      Scanner fileScanner = new Scanner(file);
      ArrayList<Integer> A1 = new ArrayList<>();
      String data = new String("");
      data = fileScanner.nextLine();
      for (int i = 0; i < data.length(); i++) {
        if (data.charAt(i) == ',')
          continue;
        String num = "";
        while (i < data.length() && data.charAt(i) != ',')
          num += data.charAt(i++);
        res.add(Integer.parseInt(num));
      }
    } catch (FileNotFoundException e) {
      System.out.println("file not found");
    }
    return res;
  }

  public static void main(String[] args) {
    MPI.Init(args);
    int rank = MPI.COMM_WORLD.Rank();
    int size = MPI.COMM_WORLD.Size();
    int MainThread = 0;
    if (rank == MainThread) {
      String workingDirectory = Paths.get("").toAbsolutePath().toString();
      ArrayList<Integer> A1 = fileToArrayList(workingDirectory + "/A1.txt");
      ArrayList<Integer> A2 = fileToArrayList(workingDirectory + "/A2.txt");
      int A1Ints[] = A1.stream().mapToInt(i -> i).toArray();
      int A2Ints[] = A2.stream().mapToInt(i -> i).toArray();
      int NumberOfElementEach = A1.size() / 4;

      MPI.COMM_WORLD.Bcast(new int[]{NumberOfElementEach}, 0, 1, MPI.INT, MainThread);

      for (int i = 1; i < size; i++) {
        MPI.COMM_WORLD.Send(A1Ints, (i - 1) * NumberOfElementEach, NumberOfElementEach, MPI.INT, i, 1);
        MPI.COMM_WORLD.Send(A2Ints, (i - 1) * NumberOfElementEach, NumberOfElementEach, MPI.INT, i, 2);
      }

      int res[] = new int[A1Ints.length];

      for (int i = 1; i < size; i++) {
        MPI.COMM_WORLD.Recv(res, (i - 1) * NumberOfElementEach, NumberOfElementEach, MPI.INT, i, 3);
      }

      for(int i : res)
        System.out.print(i + " ");

    } else {
      int dummy[] = new int[8];
      int NumberOfElementEach = 0;
      MPI.COMM_WORLD.Bcast(dummy, 0, 1, MPI.INT, MainThread);
      NumberOfElementEach = dummy[0];

      int a1[] = new int[NumberOfElementEach];
      int a2[] = new int[NumberOfElementEach];
      int res[] = new int[NumberOfElementEach];
      MPI.COMM_WORLD.Recv(a1,0,NumberOfElementEach,MPI.INT,MainThread,1);
      MPI.COMM_WORLD.Recv(a2,0,NumberOfElementEach,MPI.INT,MainThread,2);
      for (int i = 0 ; i < NumberOfElementEach; i++ )
      {
        res[i] = a1[i] + a2[i];
      }
      MPI.COMM_WORLD.Send(res,0,NumberOfElementEach, MPI.INT, MainThread,3);
    }
    MPI.Finalize();
  }
}