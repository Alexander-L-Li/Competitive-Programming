import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException{
    Scanner sc = new Scanner(new FileReader("buckets.in"));
    String brigade = "";
    int bx = 0; int by = 0;
    int rx = 0; int ry = 0;
    int lx = 0; int ly = 0;
    for(int i=0; i<10; i++){
      brigade = sc.next();
      for(int j=0; j<10; j++){
        char c = brigade.charAt(j);
        if(c == 'B'){
          by = i + 1;
          bx = j + 1;
        } else if (c == 'L'){
          ly = i + 1;
          lx = j + 1;
        } else if (c == 'R'){
          ry = i + 1;
          rx = j + 1;
        }
      }
    }

    int base = Math.max(bx, lx) - Math.min(bx, lx);
    int height = Math.max(by, ly) - Math.min(by, ly);
    int ans = base + height - 1;

    if (rx == bx && bx == lx && ry < by && ry > ly){
      ans += 2;
    } else if (ry == by && by == ly && rx < bx && rx > lx){
      ans += 2;
    }

    PrintWriter out = new PrintWriter(new File("buckets.out"));
    out.println(ans);
    out.close();
    sc.close();
  }
}
