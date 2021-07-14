#include <iostream>

using namespace std;

int main() {
  int n; cin >> n;
  int arr[n];
  for(int a=0; a<n; a++){
    int ax, ay, bx, by, fx, fy;
    cin >> ax >> ay >> bx >> by >> fx >> fy;
    int width = abs(by - ay), length = abs(ax - bx);
    int ans = length + width;
    if((ax == bx && bx == fx && fy > min(ay, by) && fy < max(ay, by)) || (fy == ay && ay == by && fx > min(ax, bx) && fx < max(ax, bx))){
      ans += 2;
    } 
    arr[a] = ans;
  }
  for(int a=0; a<n; a++){
    cout << arr[a] << "\n";
  }
}
