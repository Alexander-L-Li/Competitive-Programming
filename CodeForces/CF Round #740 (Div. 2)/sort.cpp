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
typedef priority_queue<int, vi, greater<int>> pqid;
typedef priority_queue<ll, vll, greater<ll>> pqlld;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;

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
#define nl "\n"

void solve(){
    int n; cin >> n;
    vi v;
    F0R(a, n){
        int b; cin >> b;
        v.pb(b);
    }
    int ans = 0; bool done = false; int count = 0;
    while(!done){
        bool ok = true;
        F0R(a, n-1){
            if(v[a] > v[a+1]){
                ok = false;
            }
        }
        if(ok == true){
            done = true;
            break;
        }
        count++;
        F1R(a, n){
            if(count % 2 == 0 && a % 2 == 0 && v[a-1] > v[a]){
                swap(v[a-1], v[a]);
                a++;
            } else if(count % 2 != 0 && a % 2 != 0 && v[a-1] > v[a]){
                swap(v[a-1], v[a]);
                a++;
            }
        }
        ans++;
    }
    cout << ans << nl;
}

int main(){
    int t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
}
