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
    int W, H; cin >> W >> H;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int w, h; cin >> w >> h;
    if(x2-x1 + w <= W && y2-y1 + h <= H){
        cout << min(min(max(0, h-y1), max(0, y2-H+h)), min(max(0, w-x1), max(0, x2-W+w)));
    } else if(x2-x1 + w > W && y2-y1 + h <= H){
        cout << min(max(0, h-y1), max(0, y2-H+h));
    } else if(x2-x1 + w <= W && y2-y1 + h > H){
        cout << min(max(0, w-x1), max(0, x2-W+w));
    } else {
        cout << -1;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
