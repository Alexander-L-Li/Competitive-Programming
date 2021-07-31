#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long double ld;
typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<(a); i++)

#define mp make_pair
#define pb push_back
#define f first
#define s second


void solve(){
    ll n; cin >> n;
    vpl v;
    F0R(a, n){
        ll b, c; cin >> b >> c;
        v.pb(mp(c, b));
    }
    sort(v.begin(), v.end());
    ll ans = 0; ll b = -1;
    F0R(a, v.size()){
        if(v[a].second >= b){
            ans++;
            b = v[a].first;
        }
    }
    cout << ans;
}

int main(){
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
