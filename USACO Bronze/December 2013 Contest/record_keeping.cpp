#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main(){
    freopen("records.in", "r", stdin);
    freopen("records.out", "w", stdout);
    int n; cin >> n;
    map<vector<string>, int> m;
    vector<vector<string>> v;
    for(int a=0; a<n; a++){
        string s1, s2, s3; cin >> s1 >> s2 >> s3;
        v.push_back({s1, s2, s3});
    }
    int ans = 0;
    for(int a=0; a<n; a++){
        sort(v[a].begin(), v[a].end());
        if(m.find(v[a]) == m.end()){
            m[v[a]] = 1;
        } else {
            m[v[a]]++;
            ans = max(ans, m[v[a]]);
        }
    }
    cout << ans;
}
