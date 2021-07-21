#include <bits/stdc++.h>
#include <vector>

using namespace std;
vector<char> v;

int check(){
  int count = v.size();
  for(int a=0; a<v.size(); a++){
    for(int b=a+1; b<v.size(); b++){
        if(v[a] == v[b]){
          count -= 2;
        }
      }
    }
    v.clear();
  return count;
}

int main() {
  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);

  string cows; cin >> cows; bool started = false;
  int ans = 0;
  for(int a=65; a<91; a++){
    for(int b=0; b<52; b++){
      if((char)a == cows[b] && started == false){ 
        started = true; 
      } else if ((char)a == cows[b] && started == true){
        started = false;
        ans += check();
        break;
      } else if (started == true){
        v.push_back(cows[b]);
      }
    }
  }
  cout << ans/2;
}
