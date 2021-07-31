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
    ll n; cin >> n;
    vll cows(n);
    F0R(a, n){
        cin >> cows[a];
    }
    sort(cows.begin(), cows.end(), greater<ll>());
    qll line;
    F0R(a, n){
        if(line.empty()){
            line.push(cows[a]);
        } else {
            if(line.size() <= cows[a]){
                line.push(cows[a]);
            } else {
                continue;
            }
        }
    }
    cout << line.size();

}

int main(){
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
