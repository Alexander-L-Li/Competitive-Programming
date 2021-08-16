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

void setIO(string name = "tracing"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int MAXI = 101;
const int MAXK = 252;
int n, t; 
string s;
bool cows[MAXI];
bool p1[MAXI]; bool p2[MAXK];
int cowx[MAXK], cowy[MAXK];

bool check(int x, int k){
    bool infected[101] = {false};
    infected[x] = true;
    int num[101] = {0};
    F0R(a, 251){
        int b = cowx[a], c = cowy[a];
        if(infected[b]){
            num[b]++;
        }
        if(infected[c]){
            num[c]++;
        }
        if(num[b] <= k && infected[b]){
            infected[c] = true;
        }
        if(num[c] <= k && infected[c]){
            infected[b] = true;
        }
    }
    FOR(a, 1, n+1){
        if(infected[a] != cows[a]){
            return false;
        }
    }
    return true;
}

void solve(){
    cin >> n >> t >> s;
    FOR(a, 1, n+1){
        cows[a] = s[a-1]=='1';
    }
    F0R(a, t){
        int b, c, d; cin >> b >> c >> d;
        cowx[b] = c;
        cowy[b] = d;
    }
    int ans = 0, ans2 = 251, ans3 = 0;
    FOR(a, 1, n+1){
        FOR(b, 0, 252){
            if(check(a, b)){
                p1[a] = true;
                p2[b] = true;
            }
        }
    }
    F0R(a, 252){
        if(p2[a]){
            ans3 = a;
        }
    }
    for(int a=251; a>=0; a--){
        if(p2[a]){
            ans2 = a;
        }
    }
    FOR(a, 1, n+1){
        if(p1[a]){
            ans++;
        }
    }
    if(ans3 == 251){
        cout << ans << " " << ans2 << " Infinity" << endl;
    } else {
        cout << ans << " " << ans2 << " " << ans3 << endl;
    }
}

int main(){
    setIO();
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
