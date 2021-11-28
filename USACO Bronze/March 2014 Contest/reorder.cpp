#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("reorder.in", "r", stdin);
    freopen("reorder.out", "w", stdout);
    int n; cin >> n;
    int arr[n], arr2[n];
    for(int a=0; a<n; a++){
        cin >> arr[a];
    }
    for(int a=0; a<n; a++){
        cin >> arr2[a];
    }
    int shifts = 0; int maxCows = 0;
    for(int a=0; a<n; a++){
        if(arr[a] != arr2[a]){
            shifts++;
            int count = 1;
            while(arr[a] != arr2[a]){
                for(int b=0; b<n; b++){
                    if(arr2[b] == arr[a]){
                        swap(arr[a], arr[b]);
                        count++;
                    }
                }
            }
            maxCows = max(count, maxCows);
        } 
    }
    if(shifts == 0){
        maxCows = -1;
    }
    cout << shifts << " " << maxCows;
}
