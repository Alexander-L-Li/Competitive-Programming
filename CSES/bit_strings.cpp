#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
#define ll long long
 
int main(){
  ll n; cin >> n; ll ans = 1;
  for(int i=0; i<n; i++){
    ans = 2*ans%((int)1e9+7);
  }
  cout << ans;
}
