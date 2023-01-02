#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;
int n;
int arr[MAXN][MAXN];

int solve(int row, int col){
    if(row >= n){
        return 0;
    }
    return arr[row][col] + max(solve(row+1, col), solve(row+1, col+1));
}
int main(){
    cin >> n;
    for(int a=0; a<n; a++){
        for(int b=0; b<=a; b++){
            cin >> arr[a][b];
        }
    }
    cout << solve(0, 0);
}
