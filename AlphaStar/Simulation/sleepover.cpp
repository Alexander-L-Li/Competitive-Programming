#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    int A[n+1];
    for(int a=1; a<=n; a++){
        A[a] = a;
    }
    int pos = 1, res = -1;
    while(A[pos] > 0){
        A[pos] = 0;
        res = pos;
        pos *= 2;
        if(pos > n){
            pos = pos % n;
        }
    }
    cout << res;
    
}
