#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n; cin >> n;
    char arr[n][n];
    for(int a=0; a<n; a++){
        for(int b=0; b<n; b++){
            cin >> arr[a][b];
        }
    }
    int ans = 0;
    for(int a=n-1; a>=0; a--){
        for(int b=n-1; b>=0; b--){
            if(arr[a][b] == '1'){
                ans++;
                for(int c=0; c<=a; c++){
                    for(int d=0; d<=b; d++){
                        if(arr[c][d] == '1'){
                            arr[c][d] = '0';
                        } else {
                            arr[c][d] = '1';
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}
