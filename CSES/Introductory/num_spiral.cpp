#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
int main(){
  long long t; 
  cin >> t; 
  long long y; long long x;
  long long z; long long temp; long long z2;
  long long temp2;
  while(t--){
    cin >> y; cin >> x;
    z = max(x,y);
    z2 = min(x,y);
    temp = z*z;
    temp2 = (z - 1) * (z - 1);
    if((z == x && z % 2 != 0 ) || ( z == y && z % 2 == 0)){
      cout << (temp - z2) + 1 << "\n";
    } else if ((z==x && z % 2 == 0) || (z == y && z % 2 != 0)){
      cout << temp2 + z2 << "\n";
    }
  }
 
}
