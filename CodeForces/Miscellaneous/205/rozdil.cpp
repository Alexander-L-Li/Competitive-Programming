#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  vector<int> v(n);
  int m = 1e9; int ans = 0;
  for(int a=0; a<n; a++){
    cin >> v[a];
    if(v[a] <= m){
      ans = a+1;
    }
    m = min(m, v[a]);
  }
  int count = 0;
  for(int a=0; a<n; a++){
    if(m == v[a]){  
      count++;
    }
  }
  if(count > 1){
    cout << "Still Rozdil";
  } else {
    cout << ans;
  }
}
