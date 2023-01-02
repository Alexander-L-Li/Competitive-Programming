#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 101;

int n, m;
char maze[MAXN][MAXN];
int rowdiff[] = {-1, 0, 1, 0};
int coldiff[] = {0, -1, 0, 1};
int startRow, startCol;
bool check;
string ans;

void dfs(int row, int col){
    if(maze[row][col] == 'F' && !check){
        cout << ans;
        check = true;
    }
    if(check){
        return;
    }
    maze[row][col] = '#'; 
    for(int a=0; a<4; a++){
        int nxtRow = row + rowdiff[a];
        int nxtCol = col + coldiff[a];
        if(nxtRow < 0 || nxtRow > n || nxtCol < 0 || nxtCol > m || maze[nxtRow][nxtCol] == '#'){
            continue;
        }
        if(nxtRow > row){
            ans += 'D';
        } else if(nxtRow < row){
            ans += 'U';
        } else if(nxtCol > col){
            ans += 'R';
        } else if(nxtCol < col){
            ans += 'L';
        }
        dfs(nxtRow, nxtCol);
        ans.pop_back();
    }
}

int main(){  
    cin >> n >> m;
    ans = "";
    check = false;
    for(int a=0; a<n; a++){
        for(int b=0; b<m; b++){
            cin >> maze[a][b];
            if(maze[a][b] == 'S'){
                startRow = a; startCol = b;
            }
        }
    }
    dfs(startRow, startCol);
    cout << ans;
}
