#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1e5;
vector<int> adj[MAXN+1];

int dfs(int node, int parent){
    int ans = 0;
    int cows = adj[node].size();

    if(parent == -1){
        cows++;
    }

    int k = 1;
    int days = 0;

    while(k < cows){
        days++;
        k *= 2;
    }

    ans += days;

    for(int next : adj[node]){
        if(next != parent){
            ans += dfs(next, node) + 1;
        }
    }
    
    return ans;
}

int main(){
    int n; cin >> n;
    for(int a=0; a<n-1; a++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << dfs(1, -1);
}
