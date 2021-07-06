import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException{
    Scanner sc = new Scanner(new FileReader("factory.in"));
    int n = sc.nextInt();
    int receive[] = new int[101];
    int give[] = new int[101];

    for(int i=0; i<n-1; i++){
      int a = sc.nextInt();
      int b = sc.nextInt();
      give[a] = a;
      receive[b] = b;
    }

    System.out.println(Arrays.toString(give));
    System.out.println(Arrays.toString(receive));

    int ans = -1;
    for(int i=1; i<n; i++){
      if(give[i] == 0 && ans != -1) {
        ans = -1;
        break;
      }
      if(give[i] == 0){ 
        ans = i; 
      }
    }
    PrintWriter pw = new PrintWriter(new File("factory.out"));
    pw.println(ans);
    pw.close();
    sc.close();
  }
}
