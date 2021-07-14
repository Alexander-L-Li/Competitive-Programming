#include <iostream>

using namespace std;

int main() {
  int n; cin >> n;
  int arr[n]; int ans = 0;
  for(int a=0; a<n; a++){
    cin >> arr[a];
  }
  for(int a=0; a<n; a++){
    for(int b=a; b<n; b++){
      int sum = 0;
      for(int c=b; c>=a; c--){
        sum += arr[c];
      }
      for(int c=b; c>=a; c--){
      if(arr[c] * (b-a + 1) == sum){
        ans += 1;
        break;
      }
      }
    }
  }
  cout << ans;
}
