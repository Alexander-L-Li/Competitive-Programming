#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;
  for(int a=0; a<t; a++){
    int n; cin >> n;
    vector <int> v;
    int num = 1, sum = 1;
    v.push_back(1);
    if(n != 2){
    for(int b=0; b<n; b++){
      if(sum == n){
        break;
      }
      if(b == 0 || (n % 2 == 0 && n-sum == num + 1)){
        num += 1;
      } else {
        num += 2;
      }
      v.push_back(num);
      sum += num;
    }
    if(sum > n){
      v.clear(); v.push_back(1); num = 1, sum = 1;
      for(int b=0; b<n; b++){
        if(sum == n){
          break;
        }
        if(b == 0){
          num += 2;
        } else {
          num += 1;
        }
        v.push_back(num);
        sum += num;
      }
    }
    //for(int a=0; a<v.size(); a++) cout << v[a] << "\n";
    //cout << " " << v.size() << " " << sum << "\n";
    cout << v.size() << "\n";
    v.clear();
  } else {
    cout << 2 << "\n";
  }
  }
}




