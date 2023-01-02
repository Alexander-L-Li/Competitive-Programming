#include <iostream>

using namespace std;

/* 
Sol 1:
find start position, increase ans by 2
make a flood fill
for every position, count how many neighbors in that position is a package 
    - increase ans by however much that is
continue with the neighbor if the neighbor has neighbor that is a package

Sol 2: Using right hand rule
Like solving a maze, follow the right hand side until u get back to the start position
*/
const int MAXN = 101;
int n, ans;
char arr[MAXN][MAXN];
int xD[] = {-1, 0, 1, 0};
int yD[] = {0, 1, 0, -1};

void go(int x, int y){
    arr[x][y] = 'o';
    for(int a=0; a<4; a++){
        int xx = x + xD[a], yy = y + yD[a];
        if(xx < 0 || xx > 100 || yy < 0 || yy > 100){
            continue;
        }
        if(arr[xx][yy] == '@'){
           ans++; 
        }
    }
    for(int a=0; a<4; a++){
        int xx = x + xD[a], yy = y + yD[a];
        if(xx < 0 || xx > 100 || yy < 0 || yy > 100 || arr[xx][yy] == '@' || arr[xx][yy] == 'o'){
            continue;
        }
        go(xx, yy);
    }
}

int main(){
    cin >> n;
    for(int a=0; a<101; a++){
        for(int b=0; b<101; b++){
            arr[a][b] = '.';
        }
    }
    for(int a=0; a<n; a++){
        int x, y; cin >> x >> y;
        arr[x][y] = '@';
    }
    ans = 0; bool check = false;
    for(int a=0; a<101; a++){
        for(int b=0; b<101; b++){
            if(arr[a][b+1] == '@'){
                go(a, b);
                check = true;
                break;
            }
            if(check){break;}
        }
    }
    cout << ans;
}
