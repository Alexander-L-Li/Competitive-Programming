import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int cows = Integer.parseInt(st.nextToken());
    int h[] = new int[cows]; 
    int max[] = new int[cows];
    long count = 0;
    long spaces = 0;
    long ans = 1;
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < cows; i++) {
      h[i] = Integer.parseInt(st.nextToken());
    }
    st = new StringTokenizer(br.readLine());
    for (int j = 0; j < cows; j++) {
      max[j] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(h);
    Arrays.sort(max);
    for(int a=cows-1; a>=0; a--){
      for(int b=cows-1; b>=0; b--){
        if(h[a] <= max[b]){
          count += 1;
        }
      }
      ans = (count - spaces)*ans;
      spaces += 1;
      count = 0;
    }
    PrintWriter out = new PrintWriter(System.out);
    out.println(ans);
    out.close();
    br.close();
  }
} 
