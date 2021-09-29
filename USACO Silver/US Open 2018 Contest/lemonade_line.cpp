#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    for(int a=0; a<n; a++){
        cin >> v[a];
    }
    sort(v.begin(), v.end(), greater<int>());
    int curr = 0;
    for(int a=0; a<n; a++){
        if(curr <= v[a]){
            curr++;
        }
    }
    cout << curr;
}
