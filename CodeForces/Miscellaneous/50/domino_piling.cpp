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

void solve(){
    int m, n; cin >> m >> n;
    cout << (m * n)/2;
}

int main(){
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
