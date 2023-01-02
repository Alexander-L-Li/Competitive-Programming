#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 10;
int n;
string str;
int openCnt, ans;
int xD[] = {-1, 0, 1, 0};
int yD[] = {0, 1, 0, -1};

char arr[MAXN][MAXN];

bool valid (int x, int y){
    char ch = arr[x][y];
    if(ch == '>'|| (ch == '<' && str[str.size()-1] == '<')){
        return true;
    } 
    return false;
}

void go(int x, int y){
    //perfectly balanced
    //cout << openCnt << str.size() << str << endl;
    if(2*openCnt == str.size()){
        ans = max(ans, 2*openCnt);
        return;
    }
    //visit four neighbors
    for(int a=0; a<4; a++){
        int xx = x + xD[a], yy = y + yD[a];
        if(xx < 0 || xx >= n || yy < 0 || yy >= n || arr[xx][yy] == '.'){
            continue;
        }
        if(valid(xx,yy)){
            char ch = arr[xx][yy];
            arr[xx][yy] = '.';
            str += ch;
            if(ch == '>'){
                openCnt++;
            }
        
            go(xx, yy);

            if(ch == '>'){
                openCnt--;
            }
            str.pop_back();
            arr[xx][yy] = ch;
        }
    }
}

int main(){
    cin >> n;
    for(int a=0; a<n; a++){
        for(int b=0; b<n; b++){
            cin >> arr[a][b];
        }
    }
    openCnt = 0, ans = 0;
    if(arr[0][0] == '<'){
        str = "<";
        go(0, 0);
    }
    cout << ans;
}
