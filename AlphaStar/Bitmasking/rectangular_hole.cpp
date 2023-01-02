#include <bits/stdc++.h>

using namespace std;

bool getBit(int n, int i){
    return (n & 1 << i) > 0;
}

int main(){
    int n, b; cin >> n >> b;
    int arr[n];
    for(int a=0; a<n; a++){
        cin >> arr[a];
    }
    int best = INT_MAX;
    for(int a=0; a<pow(2, n); a++){
        int total_height = 0;
        for(int b=0; b<n; b++){
            if(getBit(a, b) == true){
                total_height += arr[b];
            }
        }
        if(total_height >= b){
            best = min(best, total_height);
        }
    }
    cout << best-b;
}
