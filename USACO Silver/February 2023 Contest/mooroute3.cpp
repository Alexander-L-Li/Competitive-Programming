#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;

vector<pair<int, pair<int,int>>> adj[MAXN];
vector<pair<int, int>> prevv[MAXN];
bool visited[MAXN];
bool visited2[MAXN];
int at[MAXN];
int earliest[MAXN];

int main() {
	  int n, m; cin >> n >> m;
    fill(earliest, earliest + MAXN, INT_MAX);
    for(int a=0; a<m; a++){
          int c, r, d, s;
          cin >> c >> r >> d >> s;
          adj[c].push_back({d, {r, s}}); 
          if(c == 1){
            earliest[1] = min(earliest[1], r);
          }
          prevv[c].push_back({d, -1});
    }
    for(int a=1; a<=n; a++){
        cin >> at[a];
    }
    queue<int> q;
    if(visited[1] == false){
      q.push(1);
      visited[1] = true;
      while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int a=0; a<adj[curr].size(); a++){
          auto x = adj[curr][a];
          auto y = prevv[curr][a];
         // cout << x.first << " " << x.second.first << " " << y.second + at[x.first] << endl;
          if(y.second == -1 || (x.second.first >= y.second + at[curr])){
            //cout << "test" << x.second.second;
            if(curr != x.first && visited[x.first] == false){
              q.push(x.first);
            }
            for(int b=0; b<prevv[x.first].size(); b++){
              prevv[x.first][b].second = x.second.second;
            }
            earliest[x.first] = min(earliest[x.first], x.second.second);
          } 
          visited[x.first] = true;
        }
      }
    }
    for(auto a : prevv[2]){
      //cout << a.second << endl;
    }
    for(int a=1; a<=n; a++){
      if(earliest[a] == INT_MAX){
        cout << -1 << endl;  
      } else {
        cout << earliest[a] << endl;
      }
    }
}
