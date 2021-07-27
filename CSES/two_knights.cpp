#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
#define ll long long
 
int main(){
  ll n; 
  cin >> n;
  cout << 0 << "\n";
  for(int i=2; i<=n; i++){
   ll a1 = i*i; ll a2 = a1 * (a1-1)/2;
    if(i>2){
      a2 -= 4*(i-1)*(i-2);
    }
    cout << a2 << "\n";
  }
}
