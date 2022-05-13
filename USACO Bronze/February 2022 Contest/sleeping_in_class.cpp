#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<ll> v(n);
    ll sum = 0, prefSum = 0;
    ll count = 0;
    for(ll a=0; a<n; a++){ 
        cin >> v[a];
        sum += v[a];
    } 
    bool check = false;
    for (ll a=0; a<n; a++) {
        prefSum += v[a];
        if(prefSum == 0){
            continue;
        }
        if(sum % prefSum != 0){
            continue;
        }

        ll currSum = 0;
        for (ll b=a+1; b<n && currSum < prefSum; b++) {
            currSum += v[b];
            if (currSum == prefSum){
                currSum = 0;
            }
        }
        if(currSum == 0) {
            check = true;
            break;
        } 
    }
    if(equal(v.begin() + 1, v.end(), v.begin())){
        cout << 0;
    } else if(check){
        cout << (n - sum / prefSum);
    } else {
        cout << n-1;
    }
}

int main(){
    ll t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
