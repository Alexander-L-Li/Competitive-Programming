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

int n;
vector<string> v[100];

int common(int a, int b){
    vector<string> v1 = v[a], v2 = v[b];
    int count = 0;
    F0R(a, v1.size()){
        F0R(b, v2.size()){
            if(v1[a] == v2[b]){
                count++;
            }   
        }
    }
    return count;
}

void solve(){
    cin >> n;
    F0R(a, n){
        string s; int k;
        cin >> s >> k;
        F0R(b, k){
            string s;
            cin >> s;
            v[a].push_back(s);
        }
    }
    int ans = 0;
    F0R(a, n){
        for(int b=a+1; b<n; b++){
            ans = max(ans, common(a, b));
        }
    }
    cout << ans + 1;
}

int main(){
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
