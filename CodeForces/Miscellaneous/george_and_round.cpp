#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n, m; cin >> n >> m;
  ll arr[n], probs[m];
  bool ans[n];
  for(int a=0; a<n; a++){
    cin >> arr[a];
    ans[a] = false;
  }
  for(int a=0; a<m; a++){
    cin >> probs[a];
  }
  for(int a=0; a<n; a++){
    for(int b=0; b<m; b++){
      if(arr[a] <= probs[b]){
        ans[a] = true;
        probs[b] = -9999999999;
        break;
      }
    }
  }
  int count = 0;
  for(int a=0; a<n; a++){
    if(ans[a] == false){
      count += 1;
    }
  }
  cout << count;
}

