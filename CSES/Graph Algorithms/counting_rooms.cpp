#include <iostream>

using namespace std;

const int MAXN = 1000;

int n, m;
char arr[MAXN][MAXN];
int row[] = {0, 1, 0, -1};
int col[] = {-1, 0, 1, 0};

void dfs(int x, int y){
    arr[x][y] = '#';
    for(int a=0; a<4; a++){
        int xx = x + row[a];
        int yy = y + col[a];
        if(xx >= 0 && xx < n && yy >= 0 && yy < m && arr[xx][yy] == '.'){
            dfs(xx, yy);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int a=0; a<n; a++){
        for(int b=0; b<m; b++){
            cin >> arr[a][b];
        }
    }
    int ans = 0;
    for(int a=0; a<n; a++){
        for(int b=0; b<m; b++){
            if(arr[a][b] == '.'){
                ans++;
                dfs(a, b);
            }
        }
    }
    cout << ans;
}
