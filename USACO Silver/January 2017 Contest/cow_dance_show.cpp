#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef pair<char, char> pc;
typedef pair<string, string> ps;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<ps> vps;
typedef vector<pll> vpll;
typedef vector<pc> vpc;

template<class T> using ms = multiset<T>;
template<class T> using tup = tuple<T, T, T>;
template<class T> using pq = priority_queue<T>;
template<class T> using pqd = priority_queue<T, vector<T>, greater<T>>;

#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FOR(a, b, c) for (int a=(b); a<(c); a++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound
#define all(x) x.begin(), x.end()

void setIO(string name = "cowdance"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const char nl = '\n';
const int MAXN = 1e5;

int n, t;

bool solve(int x, int arr[]){
    int time = 0;
    pqd<int> q;
    F0R(a, n){
        if(q.size() == x){
            time = q.top();
            q.pop();
        }
        if(time + arr[a] > t){
            return false;
        }
        q.push(time + arr[a]);
    }
    return true;
}

int main(){
    setIO();
    cin >> n >> t;
    int arr[n];
    F0R(a, n){
        cin >> arr[a];
    }
    int lo = 1, hi = n;
    while(lo != hi){
        int mid = (lo + hi)/2;
        if(solve(mid, arr)){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    cout << lo;
}
