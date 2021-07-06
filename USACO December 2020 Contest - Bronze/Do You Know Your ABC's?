import java.io.*;
import java.util.*;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) throws IOException{
    Scanner sc = new Scanner(new File("temp.in"));
    int numArr[];
    numArr = new int[7];
    for (int i=0; i<7; i++){
      numArr[i] = sc.nextInt();
    }
    Arrays.sort(numArr);
    int x = numArr[0];
    int y = numArr[1];
    int z = numArr[6] - (x+y);
    int newArr[] = {x,y,z};
    Arrays.sort(newArr);
    PrintWriter out = new PrintWriter(new FileWriter("temp.out"));
    out.println(newArr[0] + " " + newArr[1] + " " + newArr[2]);
    out.close();
	  sc.close();
  }
}
