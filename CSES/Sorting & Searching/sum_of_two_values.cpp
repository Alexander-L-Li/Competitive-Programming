#include <iostream>
#include <algorithm>

using namespace std;
int n, x;
const int mxN = (int)2e5+5;
array<int, 2> arr[mxN];

void two_pointers(){
    cin >> n >> x;
    int t;
    for(int a=0; a<n; a++){
        cin >> t;
        arr[a] = {t, a+1};
    }
    sort(arr, arr + n);
    for(int a=0, b = n-1; a < b;){
        if(arr[a][0] + arr[b][0] == x){
            cout << arr[a][1] << " " << arr[b][1];
            return;
        } else if(arr[a][0] + arr[b][0] < x){
            a++;
        } else if(arr[a][0] + arr[b][0] > x){
            b--;
        }
    }
    cout << "IMPOSSIBLE";
}
int main(){
    two_pointers();
}
