#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef pair<char, char> pc;
typedef pair<string, string> ps;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tll;
typedef tuple<string, string, string> ts;
typedef tuple<char, char, char> tc;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<ps> vps;
typedef vector<pll> vpll;
typedef vector<ti> vti;
typedef vector<bool> vb;
typedef vector<ts> vts;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef multiset<string> mss;
typedef multiset<char> mc;
typedef queue<char> qc;
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
#define mt make_tuple
#define pb push_back
#define popb pop_back
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound
#define beg begin
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

void setIO(string name = "family"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int n;
string s, s2;
ps r;
vps tree; 

int solve(){
    string m1, m2, gm1, gm2, ggm1, ggm2, gggm1, gggm2;
    F0R(a, n){
        if(tree[a].first == s && tree[a].second == s2){
            r.first = s; r.second = s2; return 1;
        } else if(tree[a].first == s2 && tree[a].second == s){;
            r.first = s2; r.second = s; return 1;
        }
    }
    F0R(a, n){
        if(tree[a].second == s){
            m1 = tree[a].first; 
        } 
        if(tree[a].second == s2){
            m2 = tree[a].first; 
        }
        if(m1 == m2 && m1 != "" && m2 != ""){
            return 2;
        }
    }
    F0R(a, n){
        if(tree[a].second == s){
            m1 = tree[a].first;
        } 
        if(tree[a].second == s2){
            m2 = tree[a].first;
        }
    }
    F0R(a, n){
        if(tree[a].second == m1 && tree[a].first == s2){
            r.first = s2; r.second = s; return 3;
        } else if(tree[a].second == m2 && tree[a].first == s){
            r.first = s; r.second = s2; return 3;
        } else if(tree[a].second == m1){
            gm1 = tree[a].first;
        } else if(tree[a].second == m2){
            gm2 = tree[a].first;
        }
    }
    F0R(a, n){
        if(tree[a].second == gm1 && tree[a].first == s2){
            r.first = s2; r.second = s; return 4;
        } else if(tree[a].second == gm2 && tree[a].first == s){
            r.first = s; r.second = s2; return 4;
        } else if(tree[a].first == gm1 && tree[a].second == s2){
            r.first = s2; r.second = s; return 8;
        } else if(tree[a].first == gm2 && tree[a].second == s){
            r.first = s; r.second = s2; return 8;
        } else if(tree[a].second == gm1){
            ggm1 = tree[a].first;
        } else if(tree[a].second == gm2){
            ggm2 = tree[a].first;
        }
    }
    F0R(a, n){
        if(tree[a].second == ggm1 && tree[a].first == s2){
            r.first = s2; r.second = s; return 5;
        } else if(tree[a].second == ggm2 && tree[a].first == s){
            r.first = s; r.second = s2; return 5;
        } else if(tree[a].first == ggm1 && tree[a].second == s2){
            r.first = s2; r.second = s; return 7;
        } else if(tree[a].first == ggm2 && tree[a].second == s){
            r.first = s; r.second = s2; return 7;
        } else if(tree[a].second == ggm1){
            gggm1 = tree[a].first;
        } else if(tree[a].second == ggm2){
            gggm2 = tree[a].first;
        }   
    }
    F0R(a, n){
        if(tree[a].first == gggm1 && tree[a].second == s2){
            r.first = s2; r.second = s; return 6;
        } else if(tree[a].first == gggm2 && tree[a].second == s){
            r.first = s; r.second = s2; return 6;
        }
    }
    string arr[] = {gm1, gm2, ggm1, ggm2, gggm1, gggm2};
    F0R(a, 6){
        FOR(b, a+1, 6){
            if(arr[a] == arr[b] && arr[a] != "" && arr[b] != ""){
                return 9;
            }
        }
    }
    return 0;
}

//1 = m, 2 = sis, 3 = gm, 4 = ggm, 5 = gggm, 6 = gga, 7 = ga, 8 = a, 9 = c

int main(){
    setIO();
    cin >> n >> s >> s2;
    F0R(a, n){
        string s3, s4; cin >> s3 >> s4;
        tree.pb(mp(s3, s4));
    }
    int ans = solve();
    if(ans == 0){
        cout << "NOT RELATED";
    } else if(ans == 1){
        cout << r.first << " is the mother of " << r.second;
    } else if(ans == 2){
        cout << "SIBLINGS";
    } else if(ans == 3){
        cout << r.first << " is the grand-mother of " << r.second;
    } else if(ans == 4){
        cout << r.first << " is the great-grand-mother of " << r.second;
    } else if(ans == 5){
        cout << r.first << " is the great-great-grand-mother of " << r.second;
    } else if(ans == 6){
        cout << r.first << " is the great-great-aunt of " << r.second;
    } else if(ans == 7){
        cout << r.first << " is the great-aunt of " << r.second;
    } else if(ans == 8){
        cout << r.first << " is the aunt of " << r.second;
    } else {
        cout << "COUSINS";
    }
}
