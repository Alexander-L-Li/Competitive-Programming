#include <iostream>
#include <bits/stdc++.h>

using namespace std;
 
int main(){
  int arr[] = {4, 6, 3, 1, 2}, arr2[] = {10, 9, 8, 7, 5};
  int size = sizeof(arr)/sizeof(arr[0]) + sizeof(arr2)/sizeof(arr2[0]);
  int n[size]; 
  sort(arr, arr+(size/2)); sort(arr2, arr2+(size/2));
  int i = 0, j = 0;
  for(int a=0; a<size; a++){
    if(arr[i] < arr2[j]){
      n[a] = arr[i];
      i++;
    } else if (arr[i] > arr2[j]){
      n[a] = arr2[j];
      j++;
    }
  }
  for(int a=0; a<size; a++){
    cout << n[a] << " ";
  }
}
