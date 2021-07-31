#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main(){
    int n = 4;
    int arr[n];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    sort(arr, arr+n);
    cout << arr[3] - arr[1] << " " << arr[3] - arr[2] << " " << arr[3] - arr[0];
}
