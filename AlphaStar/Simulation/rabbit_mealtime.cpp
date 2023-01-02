#include <bits/stdc++.h>
#include <climits>

typedef long long ll;

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int rX[n], rY[n];
    bool hasSeat[n];
    for(int a=0; a<n; a++){
        hasSeat[a] = false;
        int x, y; cin >> x >> y;
        rX[a] = x; rY[a] = y;
    }
    for(int a=0; a<m; a++){
        int x, y; cin >> x >> y;
        ll minDist = LLONG_MAX;
        int rabbit = -1;
        for(int b=0; b<n; b++){
            if(hasSeat[b]){
                continue;
            }
            ll dist = pow(abs(rX[b]-x), 2) + pow(abs(rY[b]-y), 2);
            if(dist < minDist){
                minDist = dist;
                rabbit = b;
            }
        }
        hasSeat[rabbit] = true;
    }
    bool check = false;
    for(int a=0; a<n; a++){
        if(!hasSeat[a]){
            check = true;
            cout << a+1 << endl;
        }
    }
    if(!check){
        cout << 0;
    }
    
    
}
