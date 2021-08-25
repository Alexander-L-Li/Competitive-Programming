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
const int MAXN = 1e9;

void solve(){
    int n; cin >> n;
    int arr[n];
    int m1 = 0; int m2 = 1e9;
    F0R(a, n){
        cin >> arr[a];
        int b = arr[a];
        m1 = max(b, m1);
        m2 = min(b, m2);
    }
    int ans1 = 0, ans2 = 0;
    F0Rd(a, n){
        if(m1 == arr[a]){
            ans1 = a;
        }
    }
    F0R(a, n){
        if(m2 == arr[a]){
            ans2 = a;
        }
    } 
    if(ans1 > ans2){
        cout << abs(ans1 - 0) + abs(ans2 - (n-1)) - 1;
    } else {
        cout << abs(ans1 - 0) + abs(ans2 - (n-1));
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
