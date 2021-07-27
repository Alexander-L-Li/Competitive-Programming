#include <iostream>
#include <vector>

using namespace std;

const int mxN = 1e5;
int n, m;
vector<int> adj[mxN], ans;
bool visited[mxN];

void dfs(int a){
    visited[a] = 1;
    for(int v : adj[a]){
        if(!visited[v]){
            dfs(v);
        }
    }   

}
int main(){
    cin >> n >> m; int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int a=0; a<n; a++){
        if(!visited[a]){
            ans.push_back(a);
            dfs(a);
        }
    }   
    cout << ans.size() - 1 << "\n";
    for(int a=1; a<ans.size(); a++){
        cout << ans[0] + 1 << " " << ans[a] + 1 << "\n";
    }
}
