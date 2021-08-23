#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <cmath>

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
typedef vector<ps> vps;
typedef vector<pll> vpll;
typedef vector<ti> vti;
typedef vector<bool> vb;
typedef vector<ts> vts;
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

#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
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
#define nl endl

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vi v, v2;
    F0R(a, n){
        int b; cin >> b;
        v.pb(b);
    }
    F0R(a, m){
        int b; cin >> b;
        v2.pb(b);
    }
    sort(all(v)); sort(all(v2));
    int ans = 0;
    int p1 = 0, p2 = 0;
    while(p1 < n && p2 < m){
        if(abs(v[p1]-v2[p2]) <= k){
            ans++;
            p1++; p2++;
        } else if(v[p1] > v2[p2]){
            p2++;
        } else {
            p1++;
        }
    }
    cout << ans;
}

int main(){
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
