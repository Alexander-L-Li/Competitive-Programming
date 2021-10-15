#include <iostream>

using namespace std;

int main(){
    freopen("clumsy.in", "r", stdin);
    freopen("clumsy.out", "w", stdout);
    string s; cin >> s;
    int n = s.length();
    int pref[100001] = {0};
    int ans = 0;
    for(int a=1; a<=n; a++){
        if(s[a-1] == '('){
            pref[a] += pref[a-1] + 1;
        } else {
            pref[a] += pref[a-1] - 1;
        }
        if(pref[a] < 0){
            ans++; pref[a] += 2;
        }
    }
    cout << ans + pref[n]/2;
}
