#include <iostream>

using namespace std;

const int MAXN = 30;
char arr[MAXN][MAXN];
int r, c, ans;
int xD[] = {1, 0};
int yD[] = {0, 1};

void go(int x, int y){
    if(arr[x][y] == 'B'){
        ans++;
        return;
    }
    for(int a=0; a<2; a++){
        int xx = x + xD[a], yy = y + yD[a];
        if(xx < 0 || xx > r || yy < 0 || yy > c || arr[xx][yy] == 'R'){
            continue;
        }
        go(xx, yy);
    }
}

int main(){
    cin >> r >> c;
    int rS, cS; bool check = false;
    for(int a=0; a<r; a++){
        for(int b=0; b<c; b++){
            cin >> arr[a][b];
            if(arr[a][b] == 'B' && !check){
                rS = a;
                cS = b;
                check = true;
            }
        }
    }
    ans = 0;
    arr[rS][cS] = '.';
    go(rS, cS);
    cout << ans;
}
