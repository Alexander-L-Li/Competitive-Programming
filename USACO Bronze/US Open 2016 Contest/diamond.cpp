#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);
  int n, k; cin >> n >> k;
  int arr[n], ans = 0, count = 0;
  for(int a=0; a<n; a++){
    cin >> arr[a];
  } 
  for(int a=0; a<n; a++){
    for(int b=0; b<n; b++){
      if(arr[b] >= arr[a] && arr[b] <= arr[a] + k ){
        count += 1;
      }
    }
    ans = max(count, ans);
    count = 0;
    for(int b=0; b<n; b++){
      if(arr[b] >= arr[a] - k && arr[b] <= arr[a]){
        count += 1;
      }
    }
    ans = max(count, ans);
    count = 0;
  }
  cout << ans;
}
