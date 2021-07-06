import java.io.*;
import java.util.*;
import java.util.ArrayList;

public class Main {
  public static void main(String[] args) throws IOException{
    Scanner sc = new Scanner(System.in);
    String alphabet = sc.nextLine();
    String words = sc.nextLine();
    int ans = 0;
    int left = words.length();
    ArrayList word = new ArrayList();
    ArrayList alp = new ArrayList();
    for (int a = 0; a < words.length(); a++){
      char c = words.charAt(a);    
      word.add(c);
    } 
    for(int b = 0; b < alphabet.length(); b++){
      char c2 = alphabet.charAt(b);        
      alp.add(c2);
    }

   for(int c=0; c < words.length(); c+=0){
     for(int d=0; d < alphabet.length(); d++){
       if(c < words.length() && word.get(c) == alp.get(d) && left != 0){
         c += 1;
         left -= 1;
       } 
     }
      ans += 1;
     if(left == 0){
       break;
     }
   }
    
    PrintWriter out = new PrintWriter(System.out);
    out.println(ans);
    out.close();
    sc.close();
  }
}
