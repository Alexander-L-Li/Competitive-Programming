#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef pair<char, char> pc;
typedef pair<string, string> ps;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<ps> vps;
typedef vector<pll> vpll;
typedef vector<pc> vpc;

template<class T> using ms = multiset<T>;
template<class T> using tup = tuple<T, T, T>;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FOR(a, b, c) for (int a=(b); a<(c); a++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(i,a) for (auto& i : a)

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MAXN = 2e5;

vll adj[MAXN];
vll sub(MAXN);
vll ans;
ll n, k;

void dfs(int v, int p, int depth){
    ll c = 0; ll sum = 0;
    for(ll a : adj[v]){
        if(a != p){
            dfs(a, v, depth+1);
        }
    }
    for(ll a : adj[v]){
        if(a != p){
            c++;
            sum += sub[a];
        } 
    }
    sub[v] += c + sum;
    ans.pb(sub[v] - depth);
}

void solve(){
    cin >> n >> k;
    F0R(a, n-1){
        int b, c; cin >> b >> c;
        b--; c--;
        adj[b].pb(c); adj[c].pb(b);
    }
    dfs(0, -1, 0);
    sort(all(ans), greater<ll>());
    ll sol = 0; 
    F0R(a, n-k){
        sol += ans[a];
    }
    cout << sol;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
