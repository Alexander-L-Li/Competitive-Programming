import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException{
    Scanner sc = new Scanner(new File("triangles.in"));
    int range = sc.nextInt();
    int x[] = new int[range];
    int ans = 0;
    int y[] = new int[range];
    for(int i=0; i<range; i++){
      x[i] = sc.nextInt();
      y[i] = sc.nextInt();
      System.out.println("(" + x[i] + ", " + y[i] + ")");
    }
    for(int a=0; a<range; a++){
      for(int b=0; b<range; b++){
         if(a == b || x[a] != x[b]) continue;
           for(int c=0; c<range; c++){
             if(a == c || y[a] != y[c]) continue;
               ans = Math.max(ans, (Math.abs(x[c] - x[a]) * Math.abs(y[b] - y[a])));
               System.out.println(ans);
             }
           }
         }
    PrintWriter bw = new PrintWriter(new FileWriter("triangles.out"));
    bw.println(ans);
    sc.close();
    bw.close();
  }
}
