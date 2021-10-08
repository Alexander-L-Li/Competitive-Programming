#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);

    ll l, n, j, b; cin >> l >> n >> j >> b;
    vector<pair<ll, ll>> v;
    for(ll a=0; a<n; a++){
        ll c, d; cin >> c >> d;
        v.push_back(make_pair(d, c));
    }
    ll diff = j - b;
    ll ans = 0; ll prev = 0;
    sort(v.begin(), v.end(), greater<pair<ll,ll>>());
    for(ll a=0; a<n; a++){
        if(v[a].second > prev){
            ans += ((v[a].second - prev) * diff) * v[a].first;
            prev = v[a].second;
        } 
    }
    cout << ans;
}
