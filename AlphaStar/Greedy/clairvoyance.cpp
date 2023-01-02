#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    int A[2*n+1];
    fill(A, A+2*n, 0);
    for(int a=0; a<n; a++){
        int x; cin >> x;
        A[x] = 1;
    }
    int ans = 0, cnt = 0;
    for(int a=1; a<=2*n; a++){
        if(A[a] == 1){
            cnt++;
        } else if(cnt > 0){
            ans++;
            cnt--;
        }
    }   
    cout << ans;
}
