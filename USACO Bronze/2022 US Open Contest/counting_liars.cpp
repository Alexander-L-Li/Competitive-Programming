#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, char>> arr;
    for(int a=0; a<n; a++){
        char c; cin >> c;
        int x; cin >> x;
        if(c == 'G'){
            arr.push_back(make_pair(x, 'G'));
        } else {
            arr.push_back(make_pair(x, 'L'));
        }
    }
    sort(arr.begin(), arr.end());
    int ans = n;
    for(int a=0; a<n; a++){
        int sum = 0;
        for(int b=a+1; b<n; b++){
            if(arr[b].second == 'G'){
                sum++;
            } 
        }
        for(int b=0; b<a; b++){
            if(arr[b].second == 'L'){
                sum++;
            } 
        }
        ans = min(ans, sum);
    }
    cout << ans;
}
