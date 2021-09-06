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

int n, m;
int arr[MAXN], arr2[MAXN];

bool check(int r){
    int p1 = 0, p2 = 0;
    int count = 0;
    while(p1 < n && p2 < m){
        if(abs(arr[p1] - arr2[p2]) <= r){
            p1++;
        } else if(abs(arr[p1] - arr2[p2]) > r){
            p2++;
        }
    }
    if(p1 < n){
        return false;
    }
    return true;
}

void solve(){
    cin >> n >> m;
    F0R(a, n){
        cin >> arr[a];
    }
    F0R(a, m){
        cin >> arr2[a];
    }
    ll lo = 0, hi = 2e9;
    while(lo != hi){
        ll mid = (lo+hi)/2;
        if(!check(mid)){
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << lo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
