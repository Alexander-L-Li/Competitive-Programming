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
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound

void solve(){
    int n, k; cin >> n >> k;
    int x[n], y[n];
    si xfence, yfence;
    F0R(a, n){
        cin >> x[a] >> y[a];
        xfence.insert(x[a] + 1);
        yfence.insert(y[a] + 1);
    }
    int ans = 1e9;
    for(auto a = xfence.begin(); a != xfence.end(); a++){
        for(auto b = yfence.begin(); b != yfence.end(); b++){
            int temp = 0;
                int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
                F0R(c, n){
                    if(x[c] < *a && y[c] < *b){
                        q3++;
                    } else if(x[c] > *a && y[c] > *b){
                        q1++;
                    } else if(x[c] < *a && y[c] > *b){
                        q2++;
                    } else if(x[c] > *a && y[c] < *b){
                        q4++;
                    }
                }
                temp = max(max(q1, q2), max(q3, q4));
                ans = min(temp, ans);
        }
    }
    cout << ans;
}

int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
