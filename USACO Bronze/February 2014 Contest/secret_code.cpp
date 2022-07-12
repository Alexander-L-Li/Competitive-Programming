#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

set<string> codes;
string s; 

int dfs(string str){
    int ans = 1; int n = str.length();
    if(n % 2 == 0 || n == 1){
        return 1;
    }
    if(str.substr(0, n/2) == str.substr(n/2, n/2)){
        ans += dfs(str.substr(n/2, n/2+1));
    }
    if(str.substr(0, n/2) == str.substr(n/2+1, n/2)){
        ans += dfs(str.substr(n/2, n/2+1));
    }
    if(str.substr(0, n/2) == str.substr(n/2+1, n/2)){
        ans += dfs(str.substr(0, n/2+1));
    }
    if(str.substr(1, n/2) == str.substr(n/2+1, n/2)){
        ans += dfs(str.substr(0, n/2+1));
    }
    return ans;
}

int main(){
    freopen("scode.in", "r", stdin);
    freopen("scode.out", "w", stdout);
    cin >> s;
    cout << dfs(s)-1;
}
