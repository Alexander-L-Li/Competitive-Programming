#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int arr[7];
  for(int a=0; a<7; ++a){
    cin >> arr[a];
  }
  sort(arr, arr+7);
  int x = arr[0]; int y = arr[1]; int z = arr[6] - (x+y);
  int ans[3] = {x, y, z}; sort(ans, ans + 3);
  cout << x << " " << y << " " << z;
}
