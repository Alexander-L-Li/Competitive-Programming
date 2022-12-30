#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1e5;

int n, m;
int cows[MAXN+1];
vector<pair<int, pair<int,int>>> v;

bool check(int x){
  pair<int, pair<int,int>> a = pair<int, pair<int, int> > (x, {0, 0});
  int index = lower_bound(v.begin(), v.end(), a) - v.begin();
  vector<int> adj[10001];
  for(int a=index; a<m; a++){
    int x = v[a].second.first;
    int y = v[a].second.second;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int visited[10001];
  for(int a=0; a<n; a++){
    visited[a] = -1;
  }
  int count = 0;
  queue<int> q;
  for(int a=0; a<n; a++){
    if(visited[a] < 0){
      q.push(a);
      visited[a] = count;
      while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int u : adj[curr]){
          if(visited[u] < 0){
            q.push(u);
          }
          visited[u] = count;
        }
      }
      count++;
    }
  }
  for(int a=0; a<n; a++){
    if(visited[a] != visited[cows[a]]){
      return false;
    }
  }
  return true;
}

int main(){
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);
  cin >> n >> m;
  for(int a=0; a<n; a++){
    cin >> cows[a];
    cows[a]--;
  }
  v.resize(m);
  int maxweight = 0;
  for(int a=0; a<m; a++){
    cin >> v[a].second.first >> v[a].second.second >> v[a].first;
    v[a].second.first--;
    v[a].second.second--;
    maxweight = max(maxweight, v[a].first);
  }
  sort(v.begin(), v.end());
  int lo = 0, hi = maxweight + 2;
  while(lo < hi-1){
    int mid = (lo+hi)/2;
    if(check(mid)){
      lo = mid;
    } else {
      hi = mid;
    }
  }
  if(lo > maxweight){
    cout << -1;
  } else {
    cout << lo;
  }
}
