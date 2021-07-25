#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  for(int a=0; a<t; a++){
    int n; string s; cin >> n >> s;
    string sS = s;
    sort(sS.begin(), sS.end());
    int ans = 0;
    for(int b=0; b<n; b++){
      for(int c=0; c<n; c++){
        if(sS[b] == s[c] && b == c){
          ans += 1;
        }
      }
    }
    cout << n - ans << "\n";
  }
}
