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
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
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
    int k, n; cin >> k >> n;
    char ans[n][n];
    map<string, int> names;
    F0R(a, n){
        string s; cin >> s;
        names[s] = a;
    }
    F0R(a, n){
        F0R(b, n){
            if(a == b){
                ans[a][b] = 'B';
            } else {
                ans[a][b] = '?';
            }
        }
    }
    F0R(a, k){
        string paper[n];
        F0R(b, n){
            cin >> paper[b];
        }
        FOR(b, 0, n){
            bool done = true;
            for(int c=b+1; c<n; c++){
                if(paper[c-1] > paper[c]){
                    done = false;
                }
                if(done == false){
                    ans[names[paper[b]]][names[paper[c]]] = '0';
                    ans[names[paper[c]]][names[paper[b]]] = '1';
                }
            }
        }
    }
    F0R(a, n){
        F0R(b, n){
            cout << ans[a][b];
        }
        cout << endl;
    }
}
