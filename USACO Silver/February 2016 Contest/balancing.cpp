#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 1000;
int n;

int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    cin >> n;
    vector<pair<int, int>> xc;
    vector<pair<int, int>> yc;
    for(int a=0; a<n; a++){
        int x, y; cin >> x >> y;
        xc.push_back(make_pair(x, y));
        yc.push_back(make_pair(y, x));
    }   
    int ans = INT_MAX;
    sort(xc.begin(), xc.end());
    sort(yc.begin(), yc.end());
    for(int a=0; a<n-1; a++){
        int above = 0, below = 0, aleft = 0, bleft = 0;
        if(yc[a].first != yc[a+1].first){
            below = a+1;
            above = n-below;
            for(int b=0; b<n-1; b++){
                if(xc[b].second < yc[a].first+1){
                    bleft++;    
                } else if(xc[b].second > yc[a].first+1){
                    aleft++;
                }
                if(xc[b].first != xc[b+1].first){
                    ans = min(ans, max(below-bleft, max(above-aleft, max(aleft, bleft))));
                }
            }
        }
    }
    
    cout << ans;
}
