#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1001;
int n, m, cnt;
char arr[MAXN][MAXN];
int xD[] = {-1, 0, 1, 0};
int yD[] = {0, 1, 0, -1};

//process the current region
void go(int x, int y){ //floodfill function
    arr[x][y] = '.';
    cnt++;
    for(int a=0; a<4; a++){
        int xx = x + xD[a], yy = y + yD[a];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m || arr[xx][yy] == '.'){
            continue;
        }
        go(xx, yy);
    }
}

int main(){
    cin >> m >> n;
    for(int a=0; a<n; a++){
        for(int b=0; b<m; b++){
            cin >> arr[a][b];
        }
    }
    //flood fill
    int ans = 0;
    for(int a=0; a<n; a++){
        for(int b=0; b<m; b++){
            if(arr[a][b] == '*'){ //there is a new region
                cnt = 0;
                go(a, b);
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans;
}
