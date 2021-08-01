#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>

using namespace std;

typedef long double ld;
typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef queue<int> qi;
typedef queue<ll> qll;

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<(a); i++)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ub upper_bound
#define lb lower_bound

ll n, k;
const int MAXN = 2e5;
ll arr[MAXN];

bool check(ll mid){
    ll count = 0;
    for(int a=n/2; a<n; a++){
        count += max(0LL, mid - arr[a]);
    }   
    if(count <= k){
        return true;
    }
    return false;
}

void solve(){
    cin >> n >> k;
    F0R(a, n){
        cin >> arr[a];
    }
    sort(arr, arr+n);
    ll low = 1, high = 2e9;
    while(low < high){
        ll mid = low + (high - low + 1)/2;
        if(check(mid)){
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << low;
}   

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
