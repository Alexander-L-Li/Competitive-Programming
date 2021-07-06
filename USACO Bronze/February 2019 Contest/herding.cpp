#include <iostream>

using namespace std; 

int main() {
  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout);

  int arr[3];
  int ans1 = 0;
  int ans2 = 0;
  cin >> arr[0] >> arr[1] >> arr[2];
  if (abs(arr[0] - arr[1]) == 1 && abs(arr[2] - arr[1]) == 1){
    cout << 0 << "\n" << 0;
  } else if (abs(arr[0] - arr[1]) == 2 && abs(arr[2] - arr[1]) == 2){
    cout << 1 << "\n" << 1;
  } else if (abs(arr[0] - arr[1]) == 2 && abs(arr[2] - arr[1]) > 2){
    cout << 1 << "\n" << abs(arr[2] - arr[1]) - 1;
  } else if (abs(arr[0] - arr[1]) > 2 && abs(arr[2] - arr[1]) == 2){
    cout << 1 << "\n" << abs(arr[0] - arr[1]) - 1;
  } else {
    cout << 2 << "\n" << max(abs(arr[0] - arr[1]), abs(arr[2] - arr[1])) - 1;
  }
}
