#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
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

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<=(a); i++)
#define mp make_pair
#define pb push_back
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound

void solve(){
    int n; cin >> n;
    int cowa[n], cowb[n];
    F0R(a, n){
        cin >> cowa[a] >> cowb[a];
    }
    int ans = 0;
    for(int a=1; a<=3; a++){
        for(int b=1; b<=3; b++){
            for(int c=1; c<=3; c++){
                if(a == b || a == c || b == c){
                    continue;
                }
                int count = 0;
                F0R(d, n){
                    if(cowa[d] == c && cowb[d] == b){
                        count ++;
                    } else if(cowa[d] == b && cowb[d] == a){
                        count++;
                    } else if(cowa[d] == a && cowb[d] == c){
                        count++;
                    }
                }
                ans = max(count, ans);
            }
        }
    }
    cout << ans;
}

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
