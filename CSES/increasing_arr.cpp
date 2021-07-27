#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  long long n;
  long long ans = 0;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  for(int i=0; i<n-1; i++){
      if(arr[i] > arr[i+1]){
        ans += arr[i] - arr[i+1];
        arr[i+1] += arr[i] - arr[i+1];
      }
    }
  cout << ans;
}
