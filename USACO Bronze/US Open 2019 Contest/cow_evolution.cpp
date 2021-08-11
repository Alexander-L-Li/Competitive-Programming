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

void setIO(string name = "evolution"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int n;
vs v[25];
vs v2;

bool check(int x, int y){
    int c1 = 0, c2 = 0, c3 = 0;
    F0R(a, n){
        bool A = false, B = false;
        F0R(b, sz(v[a])){
            if(v[a][b] == v2[x]){
                A = true;
            }
            if(v[a][b] == v2[y]){
                B = true;
            }
        }
        if(A && B){
            c1++;
        } else if(A){
            c2++;
        } else if(B){
            c3++;
        }
    }
    if(c1 > 0 && c2 > 0 && c3 > 0){
        return true;
    }
    return false;
}

void solve(){
    cin >> n;
    F0R(a, n){
        int c;
        cin >> c;
        F0R(b, c){
            string s; cin >> s;
            v[a].pb(s);
            bool done = false;
            F0R(d, v2.size()){
                if(v2[d] == s){
                    done = true;
                }
            }
            if(!done){
                v2.pb(s);
            }
        }
    }
    string ans = "yes";
    F0R(a, v2.size()){
        bool done = false;
        FOR(b, a+1, v2.size()){
            if(check(a, b)){
                done = true;
                break;
            }
        }
        if(done){
            ans = "no";
            break;
        }
    }
    cout << ans;
}

int main(){
    setIO();
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
