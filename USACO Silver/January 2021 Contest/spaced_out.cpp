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

int main(){
    setIO();
    int n; cin >> n;
    int ans = 0;
    int arr[n][n]; 
    F0R(a, n){
        F0R(b, n){
            cin >> arr[a][b];
        }
    }
    //check for rows
    int rc = 0;
    F0R(a, n){
        int c1 = 0, c2 = 0;
        F0R(b, n){
            if(b % 2){
                c1 += arr[a][b];
            } else {
                c2 += arr[a][b];
            }
        }
        if(c1 >= c2){
            rc += c1;
        } else {
            rc += c2;
        }
    }
    int cc = 0;
    F0R(a, n){
        int c1 = 0, c2 = 0;
        F0R(b, n){
            if(b % 2){
                c1 += arr[b][a];
            } else {
                c2 += arr[b][a];
            }
        }
        if(c1 >= c2){
            cc += c1;
        } else {
            cc += c2;
        }
    }
    ans = max(cc, rc);
    cout << ans;
}
