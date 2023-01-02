#include <bits/stdc++.h>

using namespace std;

bool getBit(int n, int i){
    return (n & 1 << i) > 0;
}

int main(){
    int n; cin >> n;
    vector<pair<int, int>> v;
    int ans = 0;
    for(int a=0; a<n; a++){
        int w, h; cin >> w >> h;
        v.push_back(make_pair(w, h));
    }
    sort(v.begin(), v.end());
    for(int a=0; a<pow(2, n); a++){
        int last_height = 0, last_width = 0, total_height = 0;
        bool sorted = true;
        for(int b=0; b<n; b++){
            if(getBit(a, b) == true){
                if(v[b].first > last_width && v[b].second > last_height){
                    last_width = v[b].first;
                    last_height = v[b].second;
                    total_height++;
                } else {
                    sorted = false;
                }
            }
        }
        if(sorted == true){
            ans = max(ans, total_height);
        }
    }
    cout << ans;
}
