#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream fin("mowing.in");
  ofstream fout("mowing.out");
  vector<int> r, r2, xc, yc;
  int n, x = 0, y = 0, ans = 999999999; fin >> n;
  bool tbreak = false;
  char dir[n]; int s[n];
  for(int i=0; i<n; i++){
    fin >> dir[i] >> s[i];
  }
  for(int a=0; a<n; a++){
    for(int time = 0; time < s[a]; time++){
      if(dir[a] == 'N'){
        y += 1;
      } else if (dir[a] == 'E'){
        x += 1;
      } else if (dir[a] == 'S'){
        y -= 1;
      } else if (dir[a] == 'W'){
        x -= 1;
      }
      xc.push_back(x); yc.push_back(y);
    }
  }
  for(int a=0; a<xc.size(); a++){
    for(int b=0; b<xc.size(); b++){
      if(xc[a] == xc[b] && yc[a] == yc[b] && a != b){
        r.push_back(a+1);
        r2.push_back(b+1);
      }
    }
  }
  for(int a=0; a<r.size(); a++){
    ans = min(abs(r[a] - r2[a]), ans);
  }
  if(r.size() == 0){
    ans = -1;
  }
  fout << ans;
}
