#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long;

int main(){
    int t; cin >> t;
    for(int a=0; a<t; a++){
        long long ans = 0;
        long long n; cin >> n; long long arr[n];
        for(int b=0; b<n; b++){
            cin >> arr[b];
        }
        for(int b=0; b<n-1; b++){
            ans = max(ans, min(arr[b], arr[b+1]) * max(arr[b], arr[b+1]));
        }
        cout << ans << "\n";
    }
}

