#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;

vector<int> adj[MAXN];
int tempmax = 0;
int nextnode = 0;

void dfs(int v, int parent, int count) {
  bool check = false;
  for(int u : adj[v]){
    if(parent != u){
      check = true;
      dfs(u, v, count+1);
    }
  }
  if(!check && count > tempmax){
    tempmax = count;
    nextnode = v;
  }
}

int main() {
  int n;
  cin >> n;
  for (int a = 0; a < n - 1; a++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(0, -1, 0);
  tempmax = 0;
  dfs(nextnode, -1, 0);
  cout << tempmax;
}
