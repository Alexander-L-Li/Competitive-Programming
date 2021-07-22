#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  for(int a=0; a<t; a++){
    int n; cin >> n;
    string s = to_string(n);
    int b = s.length();
    if(n < 9){
      cout << 0 << "\n";
    } else if(s[s.length()-1] == '9'){
      int ans = n/10;
      ans ++;
      cout << ans << "\n";
    } else {
      cout << n/10 << "\n";
    }
  }
}
