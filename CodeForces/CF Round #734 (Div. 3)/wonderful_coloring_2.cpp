#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  for(int a=0; a<t; a++){
    vector <int> distinct;
    int n, k; cin >> n >> k; int arr[n];
    for(int b=0; b<n; b++){ 
      cin >> arr[b];
      bool same = false;
      for(int c=0; c<distinct.size(); c++){
        if(distinct[c] == arr[b]){
          same = true;
          break;
        }
      }
      if(same == false){
        distinct.push_back(arr[b]);
      }
    }
    int eNum = n-(n%k)/k;
    int ans[n];
    for(int b=0; b<distinct.size(); b++){
      int color = 1;
      for(int c=0; c<n; c++){
        if(distinct[b] == arr[c] && color > eNum){
          ans[c] = 0;
          break;
        } else if(distinct[b] == arr[c]){
          ans[c] = color;
          color++;
        }
      }
    }
    for(int b=0; b<n; b++){
      cout << ans[b] << " ";
    }
    cout << "\n";
  }
}
// not finished
