#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5;
int arr[N+1]; int target[N+1];
int pos[N+1];
int n;

void mod(int x, int index){
    bool check = false;
    for(int a=n-1; a>index; a--){
        if(arr[a] == x && !check){
            check = true;
        }
        if(check){
            swap(arr[a], arr[a-1]);
        }
    }
}

int main(){
    cin >> n;
    for(int a=0; a<n; a++){
        cin >> arr[a];
        pos[arr[a]] = a;
    }
    for(int a=0; a<n; a++){
        cin >> target[a];
    }
    int ans = 0;
    if(n <= 5000){
    for(int a=0; a<n; a++){
        if(target[a] != arr[a]){
            mod(target[a], a);
            ans++;
        }
    }
    } else {
        int count = 0;
        for(int a=0; a<n; a++){
            if(pos[target[a]] > a){
                ans++;
            } 
        }
    }
    cout << ans;
}
