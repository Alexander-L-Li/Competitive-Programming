#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long double ld;
typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;

#define FOR(i, a) for(int i=0; i<(a); i++)
#define FORm(i, a) for(int i=(a); i>=0; i--)

#define mp make_pair
#define pb push_back
#define f first
#define s second

void solve(){
    int n, x; cin >> n >> x;
    int arr[n];
    FOR(a, n){
        cin >> arr[a];
    }
    sort(arr, arr+n);
    ll ans = 0;
    FOR(a, n){
        if(x - arr[a] < 0){
            break;
        } else {
            x -= arr[a];
            ans++;
        }
    }
    cout << ans;
}

int main(){
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
