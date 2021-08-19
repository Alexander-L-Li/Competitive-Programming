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

int n; 
bool cows[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool good(int x, int y){
    return x>=0 && x<=n && y>=0 && y<=n;
}

bool check(int x, int y){
    if(cows[x][y] == 0){
        return 0;
    }
    int count = 0;
    F0R(a, 4){
        if(good(x + dx[a], y + dy[a])){
            if(cows[x + dx[a]][y + dy[a]]){
                count++;
            } 
        }
    }
    return count == 3;
}

int main(){
    setIO();
    cin >> n;
    int ans = 0;
    int x, y;
    F0R(a, n){
        cin >> x >> y;
        F0R(b, 4){
            if(good(x + dx[b], y + dy[b])){
                ans -= check(x + dx[b], y + dy[b]);
            }
        }
        cows[x][y] = 1;
        F0R(b, 4){
            if(good(x + dx[b], y + dy[b])){
                ans += check(x + dx[b], y + dy[b]);
            }
        }
        ans += check(x, y);
        cout << ans << endl;
    }
}
