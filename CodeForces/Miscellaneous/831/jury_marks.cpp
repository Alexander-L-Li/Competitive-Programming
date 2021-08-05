#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<char, char> pc;
typedef pair<string, string> ps;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef multiset<string> mss;
typedef queue<int> qi;
typedef queue<ll> qll;
typedef queue<string> qs;
typedef set<int> si;
typedef set<ll> sll;
typedef set<string> ss;
typedef set<char> sc;

#define FOR(a, b, c) for (int a=(b); a<(c); a++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<(a); i++)
#define mp make_pair
#define pb push_back
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound

void solve(){
    int k, n; cin >> k >> n;
    int arr[k], sum[k]; int score;
    int i;
    F0R(a, k){
        cin >> arr[a];
        i+=arr[a];
        sum[a] = i;
    }
    si ans;
    F0R(a, n){
        cin >> score;
        si temp;
        F0R(b, k){
            int x = score - sum[b];
            if(!a || ans.find(x) != ans.end()){
                temp.insert(x);
            }
        }
        ans = temp;
    }
    cout << ans.size();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
