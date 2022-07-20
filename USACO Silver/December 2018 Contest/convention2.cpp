#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int main(){
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n; cin >> n;
    vector<tuple<ll, ll, ll>> cows;
    for(ll a=0; a<n; a++){
        ll ai, ti; cin >> ai >> ti;
        cows.push_back(make_tuple(ai, a, ti));
    }
    sort(cows.begin(), cows.end());
    ll time = get<0>(cows[0]) + get<2>(cows[0]);
    ll ans = 0;
    int currcow = 1;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> cowq;
    while(currcow < n || !cowq.empty()){
        while(currcow < n && get<0>(cows[currcow]) <= time){
            cowq.push(make_tuple(get<1>(cows[currcow]), get<0>(cows[currcow]), get<2>(cows[currcow])));
            currcow++;
        }
        //cout << get<0>(cowq.top()) << "," << get<1>(cowq.top()) << "," << get<2>(cowq.top()) << " | ";
        if(cowq.empty() && currcow < n){
            time = get<0>(cows[currcow]) + get<2>(cows[currcow]);
            currcow++;
        } else if(!cowq.empty()){
            ans = max(ans, time - get<1>(cowq.top()));
            time += get<2>(cowq.top());
            cowq.pop();
        }
    }
    cout << ans;
}
