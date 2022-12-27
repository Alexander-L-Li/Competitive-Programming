#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;
 
const int MAXN = 1e5;
 
bool visited[MAXN+1];
vector<int>adj[MAXN+1];
vector<int>adj2[MAXN+1];
 
void dfs(int v, vector<int> adj[]){
    visited[v] = true;
    for(int u : adj[v]){
        if(!visited[u]){
            dfs(u, adj);
        }
    }
}
 
int main(){
    int n, m; cin >> n >> m;
    for(int a=0; a<m; a++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj2[y].push_back(x);
    }
    dfs(1, adj);
    for(int a=1; a<=n; a++){
        if(!visited[a]){
            cout << "NO" << endl << a-1 << " " << a;
            return 0;
        }
    }
    fill(visited, visited + n + 1, false);
    dfs(1, adj2);
    for(int a=1; a<=n; a++){
        if(!visited[a]){
            cout << "NO" << endl << a << " " << a-1;
            return 0;
        }
    }
    cout << "YES";
}
