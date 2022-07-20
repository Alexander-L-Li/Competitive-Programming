#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n; cin >> n;
    int arr[n];
    for(int a=0; a<n; a++){
        cin >> arr[a];
    }
    sort(arr, arr+n);
    int ans1, ans2;
    if(arr[n-2]-arr[0] == n-2 && arr[n-1]-arr[n-2] > 2){
        ans1 = 2;
    } else if(arr[n-1]-arr[1] == n-2 && arr[1]-arr[0] > 2){
        ans1 = 2;
    } else {
        int p1 = 0, p2 = 0;
        int maxRange = 0;
        for(p1 = 0; p1<n; p1++){
            while(p2 < n-1 && arr[p2+1] - arr[p1] <= n-1){
                p2++;
            }
            maxRange = max(maxRange, p2-p1+1);
        }
        ans1 = n-maxRange;
    }
    ans2 = max(arr[1]-arr[0], arr[n-1]-arr[n-2])-1 + arr[n-2]-arr[1]-n+3;
    cout << ans1 << endl << ans2;
}
