#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main(){
    freopen("cow.in", "r", stdin);
    freopen("cow.out", "w", stdout);
    int n; cin >> n;
    string s; cin >> s;
    ll c = 0, o = 0, w = 0;
    for(int a=0; a<n; a++){
        if(s[a] == 'C'){
            c++;
        } else if(s[a] == 'O'){
            o += c;
        } else {
            w += o;
        }
    }
    cout << w;
}
