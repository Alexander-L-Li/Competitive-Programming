#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> v;
    int arr[n-1];
    for(int a=0; a<n; a++){
        int b, c; cin >> b >> c;
        v.push_back(make_pair(b, c));
    }
    int temp = 0;
    for(int a=0; a<n-1; a++){
        arr[a] = abs(v[a].first - v[a+1].first) + abs(v[a].second - v[a+1].second);
        temp += arr[a];
    }
    int sum = 1e9;
    for(int a=1; a<n-1; a++){
        int diff = temp - arr[a-1] - arr[a] + abs(v[a-1].first - v[a+1].first) + abs(v[a-1].second - v[a+1].second);
        sum = min(diff, sum);
    }
    cout << sum;
}
