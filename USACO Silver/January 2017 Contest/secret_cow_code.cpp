#include <iostream>
#include <string>

using namespace std;

string s;

char dfs(long long n){
    if(n <= s.length()){
        return s[n-1];
    }
    long long len = s.length();
    while(2*len < n){
        len *= 2;
    }
    if(len + 1 != n){
        return dfs(n - (len + 1));
    } else {
        return dfs(n-1);
    }
}

int main(){
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    long long n; 
    cin >> s; 
    cin >> n;
    cout << dfs(n);
}
