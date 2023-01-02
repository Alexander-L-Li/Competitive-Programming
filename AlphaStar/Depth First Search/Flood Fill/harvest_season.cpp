#include <iostream>

using namespace std;

const int MAXN = 10;
int maze[MAXN+1][MAXN+1];
int f, cnt, ans;
int xD[] = {-1, 0, 1, 0};
int yD[] = {0, -1, 0, 1};

void dfs(int x, int y){ 
    if(x == 5 && y == 5){
        if(cnt == f){
            ans++;
        }
        return;
    }
    for(int a=0; a<4; a++){
        int xx = x + xD[a], yy = y + yD[a]; 
        if(xx < 1 || xx > 5 || yy < 1 || yy > 5 || maze[xx][yy] == 1){
            continue;
        }
        maze[xx][yy] = 1;
        cnt++;
        
        dfs(xx, yy);
        
        maze[xx][yy] = 0;
        cnt--;
    }
}

int main(){
    int k; cin >> k;
    f = 25 - k;
    ans = 0;
    for(int a=1; a<6; a++){
        for(int b=1; b<6; b++){
            maze[a][b] = 0;
        }
    }
    for(int a=0; a<k; a++){
        int x, y; cin >> x >> y;
        maze[x][y] = 1;
    }
    cnt = 1; //# of the fruits
    dfs(1,1);
    cout << ans;
}
