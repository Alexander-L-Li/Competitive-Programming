#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);
  int n; cin >> n;
  string type[n]; int low[n], high[n];
  for(int a=0; a<n; a++){
    cin >> type[a] >> low[a] >> high[a];
  }
  int ans1 = -999999999, ans2 = 999999999;
  for(int a=n-1; a>=0; a--){
    if(type[a] == "none"){
      ans1 = max(low[a], ans1);
      ans2 = min(high[a], ans2);
    } else if (type[a] == "on"){
      ans1 -= high[a];
      ans2 -= low[a];
      ans1 = max(ans1, 0);
    } else if (type[a] == "off"){
      ans1 += low[a];
      ans2 += high[a];
    }
  }
  cout << ans1 << " " << ans2 << "\n";
  ans1 = -999999999, ans2 = 999999999;
  for(int a=0; a<n; a++){
    if(type[a] == "none"){
      ans1 = max(low[a], ans1);
      ans2 = min(high[a], ans2);
    } else if (type[a] == "on"){
      ans1 += low[a];
      ans2 += high[a];
    } else if (type[a] == "off"){
      ans1 -= high[a];
      ans2 -= low[a];
      ans1 = max(ans1, 0);
    }
  }
  cout << ans1 << " " << ans2 << "\n";
  
}

//Let's first focus on predicting the range of possible rates of traffic at the end of the highway (past mile N). To do this, we start with a large possible range [a,b] (initially set to [−999999999,+999999999]) and narrow / modify it as we scan through the different highway components from miles 1…N. Every time we see a sensor reading directly from the highway, this clips the possible range [a,b] to the range given by the sensor. Every time we see an on-ramp with range [a′,b′], the new range of possible traffic flows is [a+a′,b+b′]. Similarly, when we see an off-ramp with range [a′,b′], the new range of possible traffic flow values is [a−b′,b−a′] (after this update, we set the lower end of the range to zero if it goes negative, since we can't have a negative rate of traffic flow). Predicting the range of possible initial flows is similar and essentially symmetric, where we scan backwards and keep track of a working range [a,b] that is narrowed / modified appropriately by each highway feature.
