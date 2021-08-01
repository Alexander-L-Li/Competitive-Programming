#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>

using namespace std;

typedef long double ld;
typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef queue<int> qi;
typedef queue<ll> qll;

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<(a); i++)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ub upper_bound
#define lb lower_bound

void solve(){
    int n; cin >> n;
    int ans = 0;
    int x[n], y[n];
    F0R(a, n){
        cin >> x[a];
    }
    F0R(a, n){
        cin >> y[a];
    }
    F0R(a, n){
        for(int b=a+1; b<n; b++){
            int dx = x[a] - x[b];
            int dy = y[a] - y[b];
            int squared = dx*dx + dy*dy;
            ans = max(ans, squared);
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
