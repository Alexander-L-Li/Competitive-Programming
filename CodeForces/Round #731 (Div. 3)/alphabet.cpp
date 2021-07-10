#include <iostream>

using namespace std;

int main() {
  int n; cin >> n;
  string arr[n];
  for(int a=0; a<n; a++){
    string s = ""; int c1 = 0, c2 = 1, front = 0, back = 30; bool dupe = false;
    cin >> s;
    for(int b=97; b<97+n; b++){
      for(int c=0; c<s.length(); c++){
        if(s[c] == b){
          if(b == 97){front = c; back = c;}
          if(s[back-1] == b+1){
            c2 += 1;
            back = min(back-1, back);
          } else if (s[front+1] == b+1){
            c2 += 1;
            front = max(front+1, front);
          }
        } 
      }
    }
    if(s.length() > 1 && c2 != s.length()){
      arr[a] = "NO";
    } else {
      arr[a] = "YES";
    }
  }
  for(int a=0; a<n; a++){
    cout << arr[a] << "\n";
  }
}
