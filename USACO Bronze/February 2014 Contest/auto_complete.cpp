#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    freopen("auto.in", "r", stdin);
    freopen("auto.out", "w", stdout);
    int w, n; cin >> w >> n;
    vector<pair<string, int>> words;
    for(int a=0; a<w; a++){
        string s; cin >> s;
        words.push_back(make_pair(s, a+1));
    }
    sort(words.begin(), words.end());
    for(int a=0; a<n; a++){
        int x; cin >> x;
        x--;
        string s; cin >> s;
        int lo = 0, hi = w;
        while(lo + 1 < hi){
            int mid = (lo + hi - 1)/2;
            if(words[mid].first < s){
                lo = mid + 1;
            } else {
                hi = mid + 1;
            }
        }
        int pos = lo+x;
        if(pos < words.size() && words[pos].first.size() >= s.size() && words[pos].first.find(s) == 0){
            cout << words[pos].second << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
}
