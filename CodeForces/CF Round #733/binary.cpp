#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int t; cin >> t;
  for(int a=0; a<t; a++){
    ll sum = 0;
    ll n; cin >> n;
    while(n > 0){
      sum = max(sum, n % 10);
      n = n/10;
    }
    cout << sum << "\n";
  }
}
