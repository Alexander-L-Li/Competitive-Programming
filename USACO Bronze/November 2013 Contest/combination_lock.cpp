#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    int n; cin >> n;
    int arr[3], arr2[3];
    for(int a=0; a<3; a++){
        cin >> arr[a];
    }
    for(int a=0; a<3; a++){
        cin >> arr2[a];
    }
    int ans = 0;
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            for(int c=1; c<=n; c++){
                if((abs(a-arr[0]) <= 2 || (arr[0] == 1 && a >= n-1) || (arr[0] == 2 && a == n) || (arr[0] == n && a <= 2) || (arr[0] == n-1 && a <= 1)) 
                && (abs(b-arr[1]) <= 2 || (arr[1] == 1 && b >= n-1) || (arr[1] == 2 && b == n) || (arr[1] == n && b <= 2) || (arr[1] == n-1 && b <= 1))
                && (abs(c-arr[2]) <= 2 || (arr[2] == 1 && c >= n-1) || (arr[2] == 2 && c == n) || (arr[2] == n && c <= 2) || (arr[2] == n-1 && c <= 1))){
                    ans++;
                } else if((abs(a-arr2[0]) <= 2 || (arr2[0] == 1 && a >= n-1) || (arr2[0] == 2 && a == n) || (arr2[0] == n && a <= 2) || (arr2[0] == n-1 && a <= 1)) 
                && (abs(b-arr2[1]) <= 2 || (arr2[1] == 1 && b >= n-1) || (arr2[1] == 2 && b == n) || (arr2[1] == n && b <= 2) || (arr2[1] == n-1 && b <= 1))
                && (abs(c-arr2[2]) <= 2 || (arr2[2] == 1 && c >= n-1) || (arr2[2] == 2 && c == n) || (arr2[2] == n && c <= 2) || (arr2[2] == n-1 && c <= 1))){
                    ans++;
                }
            }
        }
    }
    cout << ans;
}
