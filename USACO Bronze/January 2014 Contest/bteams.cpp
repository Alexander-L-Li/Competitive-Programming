#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 1e8;
int arr[12];
vector<vector<int>> teams(4);

void dfs(int cow){
    if(cow == 12){
        int sums[4] = {0, 0, 0, 0};
        for(int a=0; a<4; a++){
            for(int b=0; b<3; b++){
               sums[a] += teams[a][b];
            }
        }
        sort(sums, sums+4);
        ans = min(ans, sums[3]-sums[0]);
        return;
    }
    for(int a=0; a<4; a++){
        if(teams[a].size() < 3){
            teams[a].push_back(arr[cow]);
            dfs(cow+1);
            teams[a].pop_back();
        }
    }
}

int main(){
    freopen("bteams.in", "r", stdin);
    freopen("bteams.out", "w", stdout);
    for(int a=0; a<12; a++){
        cin >> arr[a];
    }
    dfs(0);
    cout << ans;
}
