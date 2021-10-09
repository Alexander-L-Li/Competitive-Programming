#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

int main(){
    freopen("slowdown.in", "r", stdin);
    freopen("slowdown.out", "w", stdout);
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> d, t;
    for(int a=0; a<n; a++){
        char c; int x; cin >> c >> x;
        if(c == 'D'){
            d.push(x);
        } else {
            t.push(x);
        }
    }
    d.push(1000);

    double currd = 0.0, currt = 0.0;
    int speed = 1;
    while(!d.empty() || !t.empty()){
        bool done = false;
        if(d.empty()){
            done = true;
        } else if(!d.empty() && !t.empty()){
            if(t.top() < (currt + (d.top() - currd)*speed)){
                done = true;
            }
        }
        if(done){
            currd += (t.top() - currt) / (speed + 0.0);
            currt = t.top();
            t.pop(); 
        } else {
            currt += (d.top() - currd) * speed;
            currd = d.top();
            d.pop();
        }
        speed++;
    }
    int ans = (int)currt;
    double x = currt - ans;
    if(x < 0.5){
        cout << ans;
    } else {
        cout << ans + 1;
    }
}
