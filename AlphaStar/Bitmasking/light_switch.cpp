#include <bits/stdc++.h>

using namespace std;

bool getBit(int n, int i){
    return (n & 1 << i) > 0;
}

int main(){
    int arr[22];
    int ans = INT_MAX;
    for(int a=1; a<=20; a++){
        cin >> arr[a];
    }
    for(int a=0; a<pow(2, 20); a++){
        int count = 0;
        int temparr[22];
        fill(temparr, temparr+22, 0);
        for(int b=1; b<=20; b++){
            if(getBit(a, b-1)){
                count++;
                temparr[b]++;
                temparr[b-1]++;
                temparr[b+1]++;
            }
        }
        bool check = false;
        for(int b=1; b<=20; b++){
            if((temparr[b] % 2 == 0 && arr[b] == 1) || (temparr[b] % 2 != 0 && arr[b] == 0)){
                check = true;
                break;
            }
        }
        if(!check){
            ans = min(ans, count);
        }
    }
    cout << ans;
}
