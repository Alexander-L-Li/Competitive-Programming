#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  int n; cin >> n;
  int maxX = 0, maxY = 0, ans = 0;
  int x[n], y[n];
  for(int a=0; a<n; a++){
    cin >> x[a] >> y[a];
  }

  for(int a=0; a<n; a++){
    for(int b=0; b<n; b++){ 
      for(int c=0; c<n; c++){
        if((x[a] == x[b] || x[b] == x[c] || x[a] == x[c]) && (a != b && b != c && a != c)){
          if(y[a] == y[b] || y[b] == y[c] || y[a] == y[c]){
            maxX = max(x[a] - x[b], max(x[a] - x[c], x[b] - x[c]));
            maxY = max(y[a] - y[b], max(y[a] - y[c], y[b] - y[c]));
            ans = max(ans, maxX * maxY);
          }
        }
        maxX = 0; maxY = 0;
      }
    }
  }
  cout << ans;
}
