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

#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
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

void solve(){
    ll x, y, z, n; cin >> x >> y >> z >> n;
    priority_queue<ll, vi, greater<ll>> p1;
    priority_queue<ll, vi, greater<ll>> p2;
    F0R(a, n){
        ll b; string s; cin >> b >> s;
        if(s == "USB"){
            p1.push(b);
        } else {
            p2.push(b);
        }
    }
    ll count = 0, count2 = 0;
    ll ans1 = 0, ans2 = 0;
    while(count < x){
        if(!p1.empty()){
            ans1 += p1.top();
            p1.pop();
            count++;
        } else {
            break;
        }
    }
    while(count2 < y){
        if(!p2.empty()){
            count2++;
            ans1 += p2.top();
            p2.pop();
        } else {
            break;
        }
    }
    ll count3 = 0; ll ans3 = 0;
    while(count3 < z){
        if(!p1.empty() && !p2.empty()){
            if(p1.top() > p2.top()){
                ans2 += p2.top();
                p2.pop();
                count3++;
            } else {
                ans1 += p1.top();
                p1.pop();
                count3++;
            }
        } else if(!p2.empty()){
            ans2 += p2.top();
            p2.pop();
            count3++;
        } else if(!p1.empty()){
            ans1 += p1.top();
            p1.pop();
            count3++;
        } else {
            break;
        }
    }
    cout << count + count2 + count3 << " " << ans1 + ans2;
}

int main(){
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
