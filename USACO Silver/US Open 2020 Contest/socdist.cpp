#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<pair<ll, ll>> v;

bool check(ll d){
	ll count = 0;
	ll curr = v[0].first, a = 0;
	while(curr <= v[m-1].second){
		if(curr >= v[a].first && curr <= v[a].second){
			count++;
			curr += d;
		} else if(curr < v[a].first){
			count++;
			curr = v[a].first + d;
		} else {
			a++;
		}
	}
	if(count < n){
		return false;
	}
	return true;
}

int main() {
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	cin >> n >> m;
	for(ll a=0; a<m; a++){
		ll x, y; cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());
	ll lo = 0, hi = 1e18;
	while(lo < hi - 1){
		ll mid = (lo + hi)/2;
		if(check(mid)){
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << lo;
}
