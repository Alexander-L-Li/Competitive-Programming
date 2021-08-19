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

void setIO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int check(string s, string s2){
    int t = 0;
    int p = 0, p2 = 0;
    while(p < s.length() && p2 < s2.length()){
        if(s[p] == s2[p2]){
            t++;
            p2++;
        }
        p++;
    }
    return (int)s.length() - t + (int)s2.length() - t;
}

vs twos; 

void solve(){
    string n; cin >> n;
    int ans = n.length() + 1;
    for(auto a : twos){
        ans = min(ans, check(n, a));
    }
    cout << ans << endl;
}

int main(){
    setIO();
    for(ll a = 1; a<=2e18; a*=2){
        twos.pb(to_string(a));
    }
    int t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
}
