#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n; cin >> n;
    vector<int> v(n*2);
    vector<int> v2(n);
    for(int a=0; a<n; a++){
        cin >> v2[a];
        v[v2[a]-1]++;
    }
    vector<int> e, b;
    for(int a=0; a<n*2; a++){
        if(v[a] == 0){
            b.push_back(a+1);
        } else {
            e.push_back(a+1);
        }
    }
    sort(e.begin(), e.end());
    sort(b.begin(), b.end());
    int ans = 0;
    while(!e.empty() && !b.empty()){
        if(b[0] > e[0]){
            b.erase(b.begin());
            e.erase(e.begin());
            ans++;
        } else {
            b.erase(b.begin());
        }
    }
    cout << ans;
}
