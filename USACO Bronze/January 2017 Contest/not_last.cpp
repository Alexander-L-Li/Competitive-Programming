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
    int n; cin >> n;
    map<string, int> m; 
    string animals[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    F0R(a, n){
        string s; int i; cin >> s >> i;
        m[s] += i;
    }
    int arr[7];
    F0R(a, 7){
        arr[a] = m[animals[a]];
    }
    sort(arr, arr + 7); string ans = "Tie";
    int count = 0;
    int smallest = arr[0]; int index;
    int small2;
    F0R(a, 7){
        if(smallest != arr[a]){
            F0R(b, 7){
                if(m[animals[b]] == arr[a]){
                    index = a;
                    small2 = arr[a];
                    ans = animals[b];
                    break;
                }
            }
            break;
        }
    }
    if(arr[index+1] == small2){
        cout << "Tie";
    } else {
        cout << ans;
    }
}   

int main(){
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
