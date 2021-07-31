#include <iostream>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    for(int a=0; a<k; a++){
        if(n % 10 == 0){
            n = n/10;
        } else {
            n -= 1;
        }
    }
    cout << n;
}
