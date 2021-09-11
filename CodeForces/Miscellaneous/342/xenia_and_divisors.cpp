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
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(i,a) for (auto i=a; i<a; i++)

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

void solve(){
    int n; cin >> n;
    vi v(8);
    F0R(a, n){
        int x; cin >> x;
        v[x]++;
    }
    int count = 0;
    vs ans;
    F0R(a, n/3){
        if(v[1] > 0 && v[2] > 0 && v[4] > 0){
            count++;
            ans.pb("1 2 4");
            v[1]--; v[2]--; v[4]--;
        } else if(v[1] > 0 && v[2] > 0 && v[6] > 0){
            count++;
            ans.pb("1 2 6");
            v[1]--; v[2]--; v[6]--;
        } else if(v[1] > 0 && v[3] > 0 && v[6] > 0){
            ans.pb("1 3 6");
            count++;
            v[1]--; v[3]--; v[6]--;
        }
    }
    if(count != n/3){
        cout << -1;
    } else {
        F0R(a, ans.size()){
            cout << ans[a] << nl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
