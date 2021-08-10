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
#define popb pop_back
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound

void setIO(string name = "milkorder"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    } 
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    int hier[m]; vpi order;
    vi cows(n);
    bool fixed = false, inHier = false;
    F0R(a, m){
        cin >> hier[a];
        if(hier[a] == 1){
            inHier = true;
        }
    } 
    F0R(a, k){
        int b, c;
        cin >> b >> c;
        order.pb(mp(b, c));
        cows[c-1] = b;
        if(b == 1){
            fixed = true;
            cout << c-1;
        }
    }
    if(!inHier && !fixed){
        int i = n - 1;
        int pointer = m - 1;
        while (pointer >= 0){
            bool done = false;
            for(int a=0; a<n; a++){
                if(cows[a] == hier[pointer]){
                    done = true;
                    i = a-1;
                    pointer -= 1;
                    break;
                }   
            }   
            if(!done){
                if(cows[i] == 0){
                    cows[i] = hier[pointer];
                    i -= 1;
                    pointer -=1;
                } else {
                    i -= 1;
                }
            }
        }
    F0R(a, n){
            if(cows[a] == 0){
                cout << a+1;
                break;
            }
    }
    } else {
        int i = 0;
        int pointer = 0;
        while(pointer < n){
            bool done = false;
            for(int a=0; a<n; a++){
                if(cows[a] == hier[pointer]){
                    done = true;
                    i = a+1;
                    pointer += 1;
                    break;
                }   
            }   
            if(!done){
                if(cows[i] == 0){
                    cows[i] = hier[pointer];
                    i += 1;
                    pointer +=1;
                } else {
                    i += 1;
                }
            }
        }
        F0R(a, n){
            if(cows[a] == 1){
                cout << a+1;
                break;
            }
        }
    }
}

int main(){
    setIO();
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
