#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  for(int a=0; a<t; a++){
    string s; cin >> s; int ans = 0;
    vector <char> distinct;
    for(int b=0; b<s.length(); b++){ 
      bool same = false;
      for(int c=0; c<distinct.size(); c++){
        if(distinct[c] == s[b]){
          same = true;
          break;
        }
      }
      if(same == false){
        distinct.push_back(s[b]);
      }
    }
    int arr[distinct.size()];
    for(int b=0; b<distinct.size(); b++){ 
      arr[b] = 0;
      for(int c=0; c<s.length(); c++){ 
        if(distinct[b] == s[c]){
          arr[b] += 1;
        }
      }
    }
    int count = 0;
    for(int b=0; b<distinct.size(); b++){ 
      if(arr[b] >= 2){
        ans += 1;
      } else if(arr[b] == 1){
        count++;  
      }
    }
    ans += count/2;
    cout << ans << "\n";
  }
}
