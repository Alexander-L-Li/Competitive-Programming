#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 100001; 
int n, m;
int minX, maxX, minY, maxY;
int X[MAXN], Y[MAXN];
vector<int> A[MAXN];
bool visited[MAXN];

void dfs(int u){
  minX = min(minX, X[u]), maxX = max(maxX, X[u]);
  minY = min(minY, Y[u]), maxY = max(maxY, Y[u]);
  visited[u] = 1;
  for(int a : A[u]){
    if(!visited[a]){
      dfs(a);
    }
  }
}

int main(){
  freopen("fenceplan.in", "r", stdin);
  freopen("fenceplan.out", "w", stdout);
  cin >> n >> m;
  for(int a=1; a<=n; a++){
    cin >> X[a] >> Y[a];
  }
  for(int a=1; a<=m; a++){
    int x, y; cin >> x >> y;
    A[x].push_back(y);
    A[y].push_back(x);
  }
  long long ans = LLONG_MAX;
  bool check = false;
  for(int a=1; a<=n; a++){
    minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
    if(!visited[a]){
      dfs(a);
      long long calc = 2*(maxX - minX) + 2*(maxY - minY);
      if(calc != 0){
        ans = min(ans, calc);
        check = true;
      }
    }
  }
  if(!check){
    cout << 0;
  } else {
    cout << ans;
  }
}
