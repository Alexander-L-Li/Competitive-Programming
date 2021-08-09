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

void setIO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve(){
    int n, k; cin >> n >> k;
    vi v1(n), v2(n);
    F0R(a, n){
        cin >> v1[a];
        v2[a] = v1[a];
    }
    sort(v2.beg(), v2.end());
    int count = 0; 
    for(int a=0; a<n-1; a++){
        count++;
        bool done = false;
        int i = ub(v2.beg(), v2.end(), v1[a]) - v2.beg();
        while(i < n && a < n-1 && v1[a+1] == v2[i]){
            a++;
            i++;
        }
    }
     if(n >= 2){
        int i = ub(v2.beg(), v2.end(), v1[n-2]) - v2.beg();
            if(v1[n-1] != v2[i]){
                count++;
            }
    }
    if(count <= k){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    setIO();
    int t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
}
