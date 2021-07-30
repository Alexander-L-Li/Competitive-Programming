#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
#define ll long long
 
int main(){
  ll t, a, b; cin >> t;
  for(int i=0; i<t; i++){
    cin >> a; cin >> b;
    cout << ((a+b) % 3 == 0 && 2*a >= b && 2*b >= a?"YES" : "NO") << "\n";
  }
}
