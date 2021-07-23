#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  for(int a=0; a<t; a++){
    int n; cin >> n;
    if(n % 3 == 0){
      cout << n/3 << " " << n/3 << "\n";
    } else if (n % 3 == 1){
      cout << n/3 + 1 << " " << n/3 << "\n";
    } else {
      cout << n/3 << " " << n/3 + 1 << "\n";
    }
  }
}
