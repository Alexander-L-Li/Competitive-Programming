#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;

void check(int left, int right, vector<int>& arr){
  int ans = 0; int dist = right-left+1;
  
  if(dist == 2){
    if(arr[left] > arr[right]){
        swap(arr[left], arr[right]);
        ans = (dist)/2 * dist;
    }
  } else {
    int mid = (left+right)/2;
    int i = left, j = mid + 1;
    bool swapit = false;
    int temp[arr.size()];
    while(i <= mid && j <= right){
      if(arr[i] > arr[j]){
        swapit = true;
      }
      temp[j] = arr[i];
      temp[i] = arr[j];
      i++; j++;
    }
    if(swapit){
      for(int a=left; a<=mid; a++){
        arr[a] = temp[a];
      }
      for(int a=mid+1; a<=right; a++){
        arr[a] = temp[a];
      }
      ans = (dist)/2 * dist;
    }
  }
  v.push_back(ans);
}

void acornSort(int left, int right, vector<int>& arr, int ans){
    if(left >= right){
        return;
    } 
    int mid = (left + right)/2;
  
    acornSort(left, mid, arr, ans);
    acornSort(mid+1, right, arr, ans);
    check(left, right, arr);
}

int main(){
    int n; cin >> n;
    n = pow(2, n);
    vector<int> arr;
    for(int a=0; a<n; a++){
      int x;
      cin >> x;
      arr.push_back(x);
    }
    acornSort(0, n-1, arr, 0);
    int ans = 0;
    for(int a=0; a<v.size(); a++){
      ans += v[a];
    }
    cout << ans << endl;
    for(int a=0; a<arr.size(); a++){
      cout << arr[a] << endl;
    }
}

