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

void setIO(string name = "badmilk"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
const int MAXM = 51;
int N, M, D, S;
int arr[MAXM];
int c1[MAXM];

void solve(){
    cin >> N >> M >> D >> S;
    vti data;
    vpi s;
    F0R(a, D){
        int b, c, d;
        cin >> b >> c >> d;
        data.pb(mt(d, c, b));
    }
    sort(all(data));
    F0R(a, S){
        int b, c;
        cin >> b >> c;
        s.pb(mp(b, c));
        for(int b=D-1; b>=0; b--){
            if(get<0>(data[b]) < s[a].second && get<2>(data[b]) == s[a].first){
                arr[get<1>(data[b])-1] += 1;
            }
        }
    }
    int ans = 0;
    F0R(a, M){
        int count = 0;
        if(arr[a] >= S){
            fill(c1, c1+N, 0);
            F0R(b, D){
                if(get<1>(data[b]) == a+1){
                    c1[get<2>(data[b])-1] = 1;
                }
            }
            F0R(b, N){
                if(c1[b] == 1){
                    count++;
                }   
            }
        }
        ans = max(count, ans);
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
