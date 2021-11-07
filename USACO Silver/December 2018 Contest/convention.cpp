#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m, c;
int arr[100001];

bool check(int x){
    int buses = 0, p = 0, cows = 0;
    for(int a=0; a<n-1; a++){
        cows++;
        if(arr[a+1] - arr[p] > x || cows >= c){
            p = a+1;
            buses++; cows = 0;
        }   
        if(buses >= m){
            return false;
        }
    }
    return true;
}   

int main(){
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> n >> m >> c;
    for(int a=0; a<n; a++){
        cin >> arr[a];
    }
    sort(arr, arr + n);
    int lo = 1, hi = 1e9;
    while(lo != hi){
        int mid = (lo + hi)/2;
        if(check(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo;
}
