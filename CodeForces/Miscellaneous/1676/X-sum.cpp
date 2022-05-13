#include <iostream>
#include <algorithm>

using namespace std;

void solve(){
  int n, m; cin >> n >> m;
  int arr[n][m];
  for(int a=0; a<n; a++){
    for(int b=0; b<m; b++){
      cin >> arr[a][b];
    }
  }
  int ans = 0;
  for(int a=0; a<n; a++){
    for(int b=0; b<m; b++){
    int x = 0;
      x += arr[a][b];
      int c = a+1, d = b+1;
      while(c < n && d < m){
          x += arr[c][d]; 
          c++; d++;
      }
      c = a-1, d = b-1;
      while(c >= 0 && d >= 0){
          x += arr[c][d]; 
          c--; d--;
      }
      c = a-1, d = b+1;
      while(c >= 0 && d < m){
          x += arr[c][d]; 
          c--; d++;
      }
      c = a+1, d = b-1;
      while(c < n && d >= 0){ 
          x += arr[c][d]; 
          c++; d--;
      }
      ans = max(x, ans);
    }
  }
  cout << ans << endl;
}

int main(){
  int t; cin >> t;
  while(t--){
    solve();
  }
}
