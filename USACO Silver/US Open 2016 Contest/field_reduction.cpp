#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> xcows;
    vector<pair<int, int>> ycows;
    for(int a=0; a<n; a++){
        int x, y; cin >> x >> y;
        xcows.push_back(make_pair(x, y));
        ycows.push_back(make_pair(y, x));
    }
    sort(xcows.begin(), xcows.end());
    sort(ycows.begin(), ycows.end());
    int ans = INT_MAX;
    int arr[4] = {0}; //XMIN, XMAX, YMIN, YMAX
    for(int a=0; a<4; a++){
        int xmin, xmax, ymin, ymax;
        for(int b=0; b<4; b++){
            for(int c=0; c<4; c++){
                arr[a]++; arr[b]++; arr[c]++; 
                xmin = xcows[arr[0]].first;
                xmax = xcows[n-1-arr[1]].first;
                ymin = ycows[arr[2]].first;
                ymax = ycows[n-1-arr[3]].first;
                int xmin2 = INT_MAX, xmax2 = INT_MIN, ymin2 = INT_MAX, ymax2 = INT_MIN;
                for(int i=0; i<n; i++){
                    if(xcows[i].second >= ymin && xcows[i].second <= ymax && xcows[i].first >= xmin && xcows[i].first <= xmax){
                        xmin2 = min(xmin2, xcows[i].first);
                        xmax2 = max(xmax2, xcows[i].first);
                    }
                    if(ycows[i].second >= xmin && ycows[i].second <= xmax && ycows[i].first >= ymin && ycows[i].first <= ymax){
                        ymin2 = min(ymin2, ycows[i].first);
                        ymax2 = max(ymax2, ycows[i].first);
                    }
                }
                ans = min(ans, (xmax2-xmin2)*(ymax2-ymin2));
                arr[a]--; arr[b]--; arr[c]--; 
            }
        }
    }
    cout << ans;
}
