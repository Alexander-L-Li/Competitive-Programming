#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
 
using namespace std;
typedef long long ll;
 
int main(){
    int t; cin >> t;
    for(int a=0; a<t; a++){
        int n, k; cin >> n >> k; ll arr[n];
        ll ans = -1e10;
        for(int b=0; b<n; b++){
            cin >> arr[b];
        }
        int l = max(l, n - 2 * k);
        for(int b=l; b<n; b++){
            for(int c=b+1; c<n; c++){
                ans = max(ans, 1LL * (b+1) * (c+1) - k * (arr[b] | arr[c]));
            }
        }
        
        cout << ans << "\n";
    }
}
 
