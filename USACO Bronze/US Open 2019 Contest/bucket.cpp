#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<char, char> pc;
typedef pair<string, string> ps;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef multiset<string> mss;
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
#define pb push_back
#define popb pop_back
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound
#define beg begin
#define all(x) x.begin(), x.end()

void setIO(string name = "buckets"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve(){
    int bx, by, lx, ly, rx, ry;
    F0R(a, 10){
        string s; cin >> s;
        F0R(b, 10){
            if(s[b] == 'B'){
                bx = a; by = b;
            } else if(s[b] == 'L'){
                lx = a; ly = b;
            } else if(s[b] == 'R'){
                rx = a; ry = b;
            }
        }
    }
    if((rx == bx && rx == lx && ry > min(ly, by) && ry < max(ly, by)) || (ry == by && ry == ly && rx > min(lx, bx) && rx < max(lx, bx))){
        cout << abs(bx - lx) + abs(by - ly) + 1 << endl;
    } else {
        cout << abs(bx - lx) + abs(by - ly) - 1 << endl;
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
