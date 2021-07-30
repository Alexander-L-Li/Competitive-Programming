#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
#define ll long long
 
int main(){
  ll n; cin >> n;
  ll ans = 0;
  for(ll i=5; i<=n; i*=5){
    ans += n/i;
  }
  cout << ans;
}
