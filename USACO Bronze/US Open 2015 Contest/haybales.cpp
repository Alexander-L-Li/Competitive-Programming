#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;

int main(){
    freopen("trapped.in", "r", stdin);
    freopen("trapped.out", "w", stdout);
    cin >> n;
    for(int a=0; a<n; a++){
        int x, s; cin >> s >> x;
        v.push_back(make_pair(x, s));
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int a=0; a<n-1; a++){
        int right = a+1;
        int left = a;
        int count = v[right].first - v[left].first;
        while(left != -1 && right != n){
            if(v[right].second < v[right].first - v[left].first){
                right++;
            } else if(v[left].second < v[right].first - v[left].first){
                left--;
            } else {
                ans += count;
                break;
            }
        }
    }
    cout << ans;
}
