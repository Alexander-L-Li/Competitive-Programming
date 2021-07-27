#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    bool arr[n];
    for(int a=0; a<n; a++){
        arr[a] = false;
        if(s1[a] != s2[a]){
            arr[a] = true;
        }
    }
    int ans = 0;
    bool temp = false;
    for(int a=0; a<n-1; a++){
        if(arr[a] == true && temp == false){
            ans++;
        }
        temp = arr[a];
    }
    cout << ans;
}
