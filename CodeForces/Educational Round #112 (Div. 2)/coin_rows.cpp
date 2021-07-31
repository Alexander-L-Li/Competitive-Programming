#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    for(int a=0; a<t; a++){
        ll n, m; cin >> m; n = 2;
        ll arr[n][m];
        for(int b=0; b<n; b++){
            for(int c=0; c<m; c++){
                cin >> arr[b][c];
            }
        }
        ll ans = 1e15;
        ll count = 0, count2 = 0;
        for(ll c=1; c<m; c++){    
            count += arr[0][c];
        }
        ans = count;
        for(ll c=1; c<m; c++){
            count -= arr[0][c];
            count2 += arr[1][c-1];
            ans = min(ans, max(count2, count));
        }
        cout << ans << "\n";
    }
}
