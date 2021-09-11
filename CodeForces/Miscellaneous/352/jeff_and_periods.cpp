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
const int MAXN = 1e6;

void solve(){
    int n; cin >> n;
    vector<vi> v(MAXN);
    F0R(a, n){
        int x; cin >> x;
        v[x].pb(a);
    }
    int count = 0;
    vpi ans;
    F0R(a, MAXN){
        if(v[a].size() > 0){
            bool done = false;
            int diff = 0;
            int temp = 0;
            F0R(b, v[a].size()-1){
                diff = v[a][b+1] - v[a][b];
                if(v[a][b+1] - v[a][b] != temp && b != 0){
                    done = true;
                    break;
                }       
                temp = diff;
            }
            if(!done){
                count++;
                ans.pb(mp(a, diff));
            }
        }
    }
    cout << count << nl;
    F0R(a, ans.size()){
        cout << ans[a].first << " " << ans[a].second << nl;
    }
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
