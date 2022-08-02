#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    vector<char> cows;
    for(int a=0; a<n; a++){
        char c; cin >> c;
        cows.push_back(c);
    }
    string s = "";
    for(int a=0; a<n-1; a+=2){
        if(cows[a] == 'H' && cows[a+1] == 'G'){
            s += 'A';
        } else if(cows[a] == 'G' && cows[a+1] == 'H'){
            s += 'B';
        }
    }
    string s2 = "";
    for(int a=0; a<s.length()-1; a++){
        if(s[a] != s[a+1]){
            s2 += s[a];
        }
    }
    s2 += s[s.length()-1];
    if(s2[s2.length()-1] == 'A'){
        cout << s2.length()-1;
    } else {
        cout << s2.length();
    }
}
