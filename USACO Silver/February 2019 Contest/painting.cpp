#include <iostream>

using namespace std;

const int MAXN = 1000;
int pref[MAXN+1][MAXN+1];

int main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int N, K; cin >> N >> K;
    for(int a=0; a<N; a++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        pref[x1][y1]++;
        pref[x1][y2]--;
        pref[x2][y1]--;
        pref[x2][y2]++;
    }
    int ans = 0;
    for(int x=0; x<MAXN; x++){
        for(int y=0; y<MAXN; y++){
            if(x > 0){
                pref[x][y] += pref[x-1][y];
            } 
            if(y > 0){
                pref[x][y] += pref[x][y-1];
            }
            if(x > 0 && y > 0){
                pref[x][y] -= pref[x-1][y-1];
            }
            if(pref[x][y] == K){
                ans++;
            }
        } 
    }
    cout << ans;
}
