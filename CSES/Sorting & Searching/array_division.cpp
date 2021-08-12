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

const int MAXN = 2e5;
int n, k;
int arr[MAXN];

bool check(ll mid){
    ll count = 0;
    ll sum = 0;
    F0R(a, n){
        if(count == k){
            return true;
        } 
        if(arr[a] + sum < mid){
            sum += arr[a];
        } else {
            count++;
            sum = 0;
            a--;
        }
    }
    return false;
}

void solve(){
    cin >> n >> k;
    ll m = 0;
    F0R(a, n){
        cin >> arr[a];
        ll b = arr[a];
        m = max(b, m);
    }
    ll lo = m; ll hi = 1e18;
    while(lo < hi){
        ll mid = (lo + hi)/2;
        if(check(mid)){
            lo = mid+1;
        } else if(!check(mid)){
            hi = mid;
        }
    }
    cout << lo - 1;
}

int main(){
    setIO();
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
