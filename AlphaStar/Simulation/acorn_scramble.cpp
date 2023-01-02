#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n, cnt, len;
    cin >> n;
    int A[n], B[n];
    for(int a=0; a<n; a++){
        cin >> A[a];
    }
    for(int a=0; a<n; a++){
        cin >> B[a];
    }
    cnt = 0, len = 0;
    for(int a=0; a<n; a++){
        if(A[a] == 0){
            continue;
        }
        cnt++;
        int curLen = 0;
        int curPos = a;
        while(A[curPos] > 0){
            curLen++;
            int curVal = A[curPos];
            A[curPos] = 0;
            for(int b=0; b<n; b++){
                if(B[b] == curVal){
                    curPos = b;
                    break;
                }
            }
        }
        A[curPos] = 0;
        len = max(len, curLen);
    }
    if(cnt == 0 || cnt == n){
        cnt = 0, len = -1;
    }
      cout << cnt << " " << len;
}
