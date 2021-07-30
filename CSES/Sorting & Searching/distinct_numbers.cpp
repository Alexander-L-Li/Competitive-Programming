#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;


int main(){
    ll n; cin >> n;
    vector<ll> v;
    ll arr[n]; 
    for(ll a=0; a<n; a++){
        cin >> arr[a];
    }
    sort(arr, arr+n);
    int count = 0;
    for(ll a=0; a<n-1; a++){
        if(arr[a] == arr[a+1]){
            count += 1;
        }
    }   
    cout << n - count;
}
