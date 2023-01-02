#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void qSort(int left, int right, vector<int>& arr){
    if(left >= right){
        return;
    } 
    int pivot = arr[right];

    int j = right;

    for(int i=left; i<j; i++){
        if(arr[i] >= pivot){
            j--;
            while(j > i && arr[j] > pivot){
                j--;
            }
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[right]);

    for(int a=0; a<arr.size(); a++){
        cout << arr[a] << " ";
    } cout << endl;

    qSort(left, j-1, arr);
    qSort(j+1, right, arr);

}

int main(){
    int n; cin >> n;
    vector<int> arr;
    for(int a=0; a<n; a++){
        int x; cin >> x;
        arr.push_back(x);
    }
    qSort(0, n-1, arr);
}
