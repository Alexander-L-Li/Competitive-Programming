#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n = 7;
    int arr[n] = {2, 3, 5, 6, 8, 10, 12};
    int target = 10;
    int left = 0, right = n-1;
    sort(arr, arr+n);
    while(left <= right){
       int mid = left + (right - left) / 2;
       if(arr[mid] == target){
           cout << arr[mid];
           break;
       } else if(arr[mid] < target){
           left = mid + 1;
       } else if(arr[mid] > target){
           right = mid - 1;
       }
    }
}
