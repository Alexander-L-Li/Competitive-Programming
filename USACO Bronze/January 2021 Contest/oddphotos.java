import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(new File("photo.in"));
    int cows = sc.nextInt();
    int id[] = new int[cows];
    boolean evengroup = true;
    boolean outbounds = false;
    int even = 0;
    int odd = 0;
    int ans = 0;
    for(int i=0; i < cows; i++){
      id[i] = sc.nextInt();
      if(id[i] % 2 == 0 && cows >= 2 && cows <= 1000 && id[i] <= 100 && id[i] >= 1){
        even += 1;
      } else if (id[i] % 2 != 0 && cows >= 2 && cows <= 1000 && id[i] <= 100 && id[i] >= 1){
        odd += 1;
      } else if (id[i] > 100 || id[i] < 1){
        outbounds = true;
      }
    }
    System.out.println(even);
    System.out.println(odd);

    for(int a=0; a<cows; a++){
      if(evengroup == true && odd >= 0 && even >= 0){
        evengroup = false;
        if(even > 0 && odd > 0){
          even -= 1;
          ans += 1;
        } else if (odd > 0){
            odd -= 2;
            ans += 1;
            a += 1;
          } else {
            ans += 1;
            break;
          }
      } else if (evengroup == false && odd >= 0 && even >= 0){
        evengroup = true;
        if(even > 0 && odd > 0){
          odd -= 1;
          ans += 1;
        } else if (odd % 3 == 0){
          odd -= 1;
          ans += 1;
        } else if (odd % 5 == 0){
          odd -= 3;
          a += 2;
          ans += 1;
        } else if (odd % 7 == 0){
          odd -= 2;
          ans += 1;
          a += 1;
        } else {
          ans += 1;
          break;
        }
      }
    }

    if(cows < 2 || cows > 1000 || outbounds == true){
      ans = 0;
    }
    
    
    PrintWriter out = new PrintWriter(new FileWriter("photo.out"));
    out.println(ans);
    System.out.println(Arrays.toString(id));
    out.close();
    sc.close();
  }
}
