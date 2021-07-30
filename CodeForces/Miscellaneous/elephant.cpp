#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ll x; cin >> x;
    ll ans=0; 
    for(ll a=0; a<x; a+=0){
        if(x - a >= 5){
            a += 5;
        } else if(x - a >= 4){
            a += 4;
        } else if(x - a >= 3){
            a += 3;
        } else if(x - a >= 2){
            a += 2;
        } else if(x - a >= 1){
            a += 1;
        }
        ans++;
    }
    cout << ans;
    
}
