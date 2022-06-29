#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("baseball.in", "r", stdin);
    freopen("baseball.out", "w", stdout);
    int n; cin >> n;
    vector<int> v;
    for(int a=0; a<n; a++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int a=0; a<n; a++){
        for(int b=a+1; b<n; b++){
            for(int c=b+1; c<n; c++){
                int d1 = v[b]-v[a];
                int d2 = v[c]-v[b];
                if(d2 <= d1*2 && d2 >= d1){
                    ans++;
                }
            }
        }
    }
    cout << ans;
}
