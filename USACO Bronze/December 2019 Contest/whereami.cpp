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

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<(a); i++)

#define mp make_pair
#define pb push_back
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound

int n;
string s;

bool check(int l){
    ss Set; 
    for(int a=0; a<=n-l; a++){
        if(Set.count(s.substr(a, l)) > 0){
            return true;
        } else {
            Set.insert(s.substr(a, l));
        }
    }
    return false;
}

void solve(){
    cin >> n >> s;
    int ans = 1; 
    while(check(ans)){
        ans++;
    }
    cout << ans;
}

int main(){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
