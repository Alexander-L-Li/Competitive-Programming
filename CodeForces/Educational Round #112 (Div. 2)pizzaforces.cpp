#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    for(int a=0; a<t; a++){
        ll n; cin >> n;
        ll ans = 0;
        if(n <= 6){
            ans = 15;
        } else {
            if(n % 2 != 0){
                n++;
            }
            ans = (n * 5)/2;
        }
        cout << ans << endl;
    }
}
