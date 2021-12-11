#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    freopen("typo.in", "r", stdin);
    freopen("typo.out", "w", stdout);
    string s; cin >> s;
    int n = s.length();
    int pref[100001] = {0};
    int ans = 0; int x = 0, y = 0;
    for(int a=1; a<=n; a++){
        if(s[a-1] == '('){
            pref[a] += pref[a-1] + 1;
            x++;
        } else {
            pref[a] += pref[a-1] - 1;
            y++;
        }
        cout << pref[a] << " ";
        if(pref[a] <= 1){
            x = 0;
        }
        if(pref[a] == -1){
            ans = y;
            break;
        }
    }
    if(pref[n] > 0){
        ans = x;
    }
    cout << ans << endl;
}
