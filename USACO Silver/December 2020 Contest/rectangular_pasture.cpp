#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ycomp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

const int MAXN = 2500;
int pref[MAXN+1][MAXN+1];
int arr[MAXN+1][MAXN+1];

int rsum(int x1, int y1, int x2, int y2){
    return pref[x1][y1] - pref[x2-1][y1] - pref[x1][y2-1] + pref[x2-1][y2-1];
}

int main(){
    int n; cin >> n;
    vector<pair<int, int>> cows;
    long long ans = 0;
    for(int a=0; a<n; a++){
        int x, y; cin >> x >> y;
        cows.push_back(make_pair(x, y));
    }
    sort(cows.begin(), cows.end());
    for(int a=0; a<n; a++){
        cows[a].first = a+1;
    }
    sort(cows.begin(), cows.end(), ycomp);
    for(int a=0; a<n; a++){
        cows[a].second = a+1;
    }
    for(int a=0; a<n; a++){
        pref[cows[a].first][cows[a].second] = 1;
    }
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            pref[a][b] += pref[a-1][b] + pref[a][b-1] - pref[a-1][b-1];
        }
    }
    for(int a=0; a<n; a++){
        for(int b=a; b<n; b++){
            int x1 = max(cows[a].first, cows[b].first);
            int x2 = min(cows[a].first, cows[b].first);
            int y1 = cows[b].second;
            int y2 = cows[a].second;
            ans += rsum(x2, y1, 1, y2) * rsum(n, y1, x1, y2);
        } 
    } 
    cout << ans + 1;
}
