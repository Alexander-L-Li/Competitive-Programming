#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(){
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    ll n, k; cin >> n >> k;
    ll pref[n]; vector<pair<ll, ll>> v;
    for(ll a=0; a<n; a++){
        ll x, y; cin >> x >> y;
        v.push_back(make_pair(y, x));
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    for(ll a=0; a<n; a++){
        sum += v[a].second;
        pref[a] = sum;
    }
    ll ans = 0;
    ll p1 = 0, p2 = 1;
    while(p1 < n && p2 < n){
        if(v[p2].first - v[p1].first <= k*2){
            ll x;
            if(p1 != 0){
                x = pref[p2] - pref[p1-1];
            } else {
                x = pref[p2];
            }
            ans = max(x, ans);
            p2++;
        } else {
            p1++;
        }
    }
    cout << ans;
}
