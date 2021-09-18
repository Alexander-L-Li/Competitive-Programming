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
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MAXN = 1e5;

void setIO(string name = "moocast"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool adj[200][200];
int n;
vb visited(MAXN);

int dfs(int v){
    visited[v] = true;
    int cows = 0;

    F0R(a, n){
        if(!visited[a] && adj[v][a]){
            visited[a] = true;
            cows += dfs(a) + 1;
        }   
    }
    return cows;
}

int main(){
    setIO();
    cin >> n;
    vi x(n), y(n), p(n);
    F0R(a, n){
        cin >> x[a] >> y[a] >> p[a];
    }
    F0R(a, n){
        F0R(b, n){
            int dist = (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
            int x = p[a] * p[a];
            if(dist <= x){
                adj[a][b] = true;
            }
        }
    }
    int ans = 0;
    F0R(a, n){
        fill(all(visited), false);
        int x = dfs(a) + 1;
        ans = max(ans, x);
    }
    cout << ans;
}
