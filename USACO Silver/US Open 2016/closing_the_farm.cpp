#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef pair<char, char> pc;
typedef pair<string, string> ps;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tll;
typedef tuple<string, string, string> ts;
typedef tuple<char, char, char> tc;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<ti> vti;
typedef vector<ts> vts;
typedef vector<bool> vb;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef multiset<string> mss;
typedef multiset<char> mc;
typedef queue<char> qc;
typedef queue<int> qi;
typedef queue<ll> qll;
typedef queue<string> qs;
typedef set<int> si;
typedef set<ll> sll;
typedef set<string> ss;
typedef set<char> sc;

#define FOR(a, b, c) for (int a=(b); a<(c); a++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<(a); i++)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define popb pop_back
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound
#define beg begin
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

void setIO(string name = "closing"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vi adj[3001], order(3001); ll nodes;
vb visited(3001), closed(3001);

void dfs(ll v){
    if(visited[v] || closed[v]){ return; }
    nodes++;
    visited[v] = true;
    for(auto& a : adj[v]){
        if(!visited[a]){
            dfs(a);
        }
    }
}

void solve(){
    ll n, m;
    cin >> n >> m;
    F0R(a, m){
        ll b, c;
        cin >> b >> c; 
        adj[b].pb(c);
        adj[c].pb(b);
    }
    F0R(a, n){
        cin >> order[a];
    }
    dfs(1);
    if(nodes == n){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    F0R(a, n-1){
        fill(all(visited), false);
        nodes = 0;
        closed[order[a]] = true;
        dfs(order[n-1]);
        if(nodes == n-(a+1)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main(){
    setIO();
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
