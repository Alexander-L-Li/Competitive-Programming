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
const int MAXN = 1e9;

void setIO(string name = "hps"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main(){
    setIO();
    int n; cin >> n;
    vi r(n), p(n), s(n);
    int s1 = 0, s2 = 0, s3 = 0;
    F0R(a, n){
        char x; cin >> x;
        if(x == 'H'){
            s1++;
        } else if(x == 'P'){
            s2++;
        } else {
            s3++;
        }
        r[a] += s1;
        p[a] += s2;
        s[a] += s3;
    }
    int ans1, ans2 = 0;
    F0R(a, n){
        int x = max(r[a], max(p[a], s[a]));
        if(r[a] == x){
            ans1 = max(p[n-1] - p[a], s[n-1] - s[a]) + x;
        } else if(p[a] == x){
            ans1 = max(r[n-1] - r[a], s[n-1] - s[a]) + x;
        } else if(s[a] == x){
            ans1 = max(r[n-1] - r[a], p[n-1] - p[a]) + x;
        }   
        ans2 = max(ans1, ans2);
    }
    cout << ans2;
}
