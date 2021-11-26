#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10001];
vector<int> adj2[10001];
int ffill[10001] = {0};

void dfs(int v, int color){
    if(ffill[v]){
        return;
    }
    ffill[v] = color;
    for(int a : adj[v]){
        dfs(a, color);
    }
}

void dfs2(int v, int color){
    if(ffill[v]){
        return;
    }
    ffill[v] = color;
    for(int a : adj2[v]){
        dfs2(a, color);
    }
}

int main(){
    freopen("cowart.in", "r", stdin);
    freopen("cowart.out", "w", stdout);
    int n; cin >> n;
    char arr[n][n];
    int nums[n][n];
    int count = 0;
    for(int a=0; a<n; a++){
        for(int b=0; b<n; b++){
            cin >> arr[a][b];
            nums[a][b] = count;
            count++;
        }
    }
    for(int a=0; a<n; a++){
        for(int b=0; b<n-1; b++){
            if((arr[a][b] == 'R' && arr[a][b+1] == 'G') || 
            (arr[a][b] == 'G' && arr[a][b+1] == 'R')){
                adj2[nums[a][b]].push_back(nums[a][b+1]); adj2[nums[a][b+1]].push_back(nums[a][b]);
            }
            if(arr[a][b] == arr[a][b+1]){
                adj2[nums[a][b]].push_back(nums[a][b+1]); adj2[nums[a][b+1]].push_back(nums[a][b]);
                adj[nums[a][b]].push_back(nums[a][b+1]); adj[nums[a][b+1]].push_back(nums[a][b]);
            }
        }
    }
    for(int b=0; b<n; b++){
        for(int a=0; a<n-1; a++){
            if((arr[a][b] == 'R' && arr[a+1][b] == 'G') || 
            (arr[a][b] == 'G' && arr[a+1][b] == 'R')){
                adj2[nums[a][b]].push_back(nums[a+1][b]); adj2[nums[a+1][b]].push_back(nums[a][b]);
            }
            if(arr[a][b] == arr[a+1][b]){
                adj2[nums[a][b]].push_back(nums[a+1][b]); adj2[nums[a+1][b]].push_back(nums[a][b]);
                adj[nums[a][b]].push_back(nums[a+1][b]); adj[nums[a+1][b]].push_back(nums[a][b]);
            }
        }
    }
    int color = 1;
    for(int a=0; a<n*n; a++){
        if(!ffill[a]){
            dfs(a, color);
            color++;
        }
    } cout << color-1;
    color = 1;
    fill(ffill, ffill + 10001, 0);
    for(int a=0; a<n*n; a++){
        if(!ffill[a]){
            dfs2(a, color);
            color++;
        }
    } cout << " " << color-1;
}
