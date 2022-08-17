#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n;
bool check(ll mid){
    ll count = 0;
    for(int a=1; a<=n; a++){
        count += min(n, mid/a);
        if(count > (n*n)/2){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n;
    ll lo = 1; ll hi = 1e12;
    while(lo < hi){
        ll mid = (hi+lo)/2;
        if(check(mid)){
            lo = mid+1;
        } else {
            hi = mid;
        }
    }
    cout << lo;
}
