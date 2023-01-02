#include <iostream>
#include <algorithm>
#include <vector>

const int MAXN = 1001;
using namespace std;
int n, q;
int D[MAXN][MAXN];
vector<vector<int>> A(MAXN);
int distances[MAXN];

void dfs(int u, int p){
    for(int a : A[u]){
        if(a != p){
            distances[a] = distances[u] + D[u][a];
            dfs(a, u);
        }
    }
}

int main(){
    cin >> n >> q;
    for(int a=1; a<n; a++){
        int u, v, w; cin >> u >> v >> w;
        D[u][v] = D[v][u] = w;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    for(int a=0; a<q; a++){
        int u, v; cin >> u >> v;
        distances[u] = 0;
        dfs(u, u);
        cout << distances[v] << endl;
    }
}
