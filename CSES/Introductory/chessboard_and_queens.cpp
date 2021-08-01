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

string arr[8];
bool d1[64], d2[64], c[64];
int ans = 0;

void dfs(int row){
    if(row == 8){
        ans++;
        return;
    } 
    F0R(a, 8){
        if(arr[row][a] == '.' && !c[a] && !d1[row + a] && !d2[a-row+7]){
            c[a] = d1[a + row] = d2[a - row + 7] = true;
            dfs(row + 1);
            c[a] = d1[a + row] = d2[a - row + 7] = false; 
        }
    }
}

void solve(){
    F0R(a, 8){
        cin >> arr[a];
        dfs(0);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
