#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    int arr[n]; int sum = 0;
    for(int a=0; a<n; a++){
        int x; cin >> x;
        sum += x;
        arr[a] = sum;
    }
    int q; cin >> q;
    for(int a=0; a<q; a++){
        int x, y; cin >> x >> y;
        if(x != y){
            cout << arr[y] - arr[x-1] << endl;
        } else {
            cout << arr[y] - arr[y-1] << endl;
        }
    }
}   
