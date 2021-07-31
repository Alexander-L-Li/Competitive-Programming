#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

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

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<(a); i++)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ub upper_bound
#define lb lower_bound


void solve(){
    int n; cin >> n;
    vi cubes(n); msi towers;
    F0R(a, n){
        cin >> cubes[a];
    }
    F0R(a, n){
        if(towers.size() == 0){
            towers.insert(cubes[a]);
        } else {
            auto base = towers.upper_bound(cubes[a]);
            if(base == towers.end()){
                towers.insert(cubes[a]);
            } else {
                towers.insert(cubes[a]);
                towers.erase(base);
            }
        }
    }
    cout << towers.size();
}

int main(){
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
