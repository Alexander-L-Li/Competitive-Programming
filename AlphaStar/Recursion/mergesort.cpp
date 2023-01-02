#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 500;

void merge(int left, int right, vector<int>& arr){
  int mid = (left+right)/2;
  int i = left, j = mid + 1;
  int k = left;
  int temp[arr.size()];

  while(i <= mid && j <= right){
    if(arr[i] < arr[j]){
      temp[k] = arr[i];
      i++;
    } else {
      temp[k] = arr[j];
      j++;
    }
    k++;
  }
  for(int x = i; x<=mid; x++){
    temp[k] = arr[x];
    k++;
  }
  for(int x = j; x<=right; x++){
    temp[k] = arr[x];
    k++;
  }
  for(int x=left; x<=right; x++){
    arr[x] = temp[x];
  }
}

void mSort(int left, int right, vector<int>& arr){
    if(left >= right){
        return;
    } 
    int mid = (left + right)/2;
  
    mSort(left, mid, arr);
    mSort(mid+1, right, arr);
    merge(left, right, arr);

   for(int a=0; a<arr.size(); a++){
      cout << arr[a] << " ";
    } cout << endl;
}

int main(){
    int n; cin >> n;
    vector<int> arr;
    for(int a=0; a<n; a++){
      int x;
      cin >> x;
      arr.push_back(x);
    }
    mSort(0, n-1, arr);
}
