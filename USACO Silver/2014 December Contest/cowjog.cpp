#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(0);
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    long long n, t; cin >> n >> t;
    vector<long long> v(n);
    for(int a=0; a<n; a++){
        int s;
        cin >> v[a] >> s;
        v[a] += t*s;
    }
    long long end = v[n-1];
    int ans = 1;
    for(int a=n-1; a>=0; a--){
        if(v[a] < end){
            end = v[a];
            ans++;
        }
    }
    cout << ans;
}
