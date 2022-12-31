#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>

using namespace std;

int n;
vector<pair<int, pair<int, int>>> v;

bool check(int x){
    int index = lower_bound(v.begin(), v.end(), make_pair(x, make_pair(0, 0))) - v.begin();
    bool visited[1000];
    vector<int> adj[1000];
    for(int a=0; a<index; a++){
        int x = v[a].second.first;
        int y = v[a].second.second;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int a=0; a<n; a++){
        visited[a] = false;
    }
    stack<int> s;
    s.push(0);
    visited[0] = true;
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        for(int u : adj[curr]){
            if(!visited[u]){
                s.push(u);
            }
            visited[u] = true;
        }
    }
    for(int a=0; a<n; a++){
        if(!visited[a]){
            return false;
        }
    }
    return true;
}

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    vector<pair<int, int>> cows;
    for(int a=0; a<n; a++){
        int x, y; cin >> x >> y;
        cows.push_back(make_pair(x, y));
    }
    for(int a=0; a<n; a++){
        for(int b=0; b<n; b++){
            if(a == b){
                continue;
            }
            int val = pow(abs(cows[a].first-cows[b].first),2) + pow(abs(cows[a].second-cows[b].second), 2);
            v.push_back(make_pair(val, make_pair(a, b)));
        }
    }
    sort(v.begin(), v.end());
    int lo = 0, hi = 1e9;
    while(lo < hi-1){
        int mid = (lo+hi)/2;
        if(check(mid)){
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << lo;
}
