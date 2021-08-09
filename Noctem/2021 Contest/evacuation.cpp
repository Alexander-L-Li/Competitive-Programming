#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<char, char> pc;
typedef pair<string, string> ps;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef multiset<string> mss;
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
#define pb push_back
#define popb pop_back
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound
#define beg begin
#define all(x) x.begin(), x.end()

void setIO(string name = "evacuation"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int MAXN = 1e5;
int n, m, k;
vector<int> adj[MAXN];
int rooms[MAXN];
bool visited[MAXN];
int ans = 1e9;

void dfs(int v, int ppl){
    visited[v] = true;
    for(int a : adj[v]){
        if(!visited[a]){
            rooms[v] += k;
            dfs(a, (ppl-k)/k);
        }
    }
    cout << rooms[v] << " ";
}

void solve(){
    cin >> n >> m >> k;
    F0R(a, n-1){
        int b, c;
        cin >> b >> c;
        b--; c--;
        adj[b].pb(c);
        adj[c].pb(b);
    }
    dfs(0, 20);
    //cout << ans;
}

int main(){
    setIO();
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
