#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);
  int x,y,m; cin >> x; cin >> y; cin >> m;
  int minxy = min(x,y);
  int mult = m/minxy;
  int ans = 0;
  for(int a=1; a<=mult; a++){
    int maxy = mult-a;
    while(true){
    if(maxy*y + a*x > m){
      maxy -= 1;
    } else {
      break;
    }
    }
    ans = max(maxy*y + a*x, ans);
  }
  cout << ans;
}
