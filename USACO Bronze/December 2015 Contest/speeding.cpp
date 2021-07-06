#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("speeding.in");
  ofstream fout("speeding.out");
  int n, m, ans = 0, temp = 0; fin >> n >> m;
  int len[n+1], limit[n], seg[m+1], speed[m];
  len[0] = 0;
  seg[0] = 0;
  for(int i=0; i<n; i++){
    fin >> len[i+1] >> limit[i];
    if(i != 0){
      len[i+1] += len[i];
    }
  }
  for(int i=0; i<m; i++){
    fin >> seg[i+1] >> speed[i];
    if(i != 0){
      seg[i+1] += seg[i];
    }
  }
  for(int a=1; a<=100; a++){
    for(int b=1; b<=n; b++){
      for(int c=1; c<=m; c++){
        if(a <= len[b] && a > len[b-1] && a <= seg[c] && a > seg[c-1]){ 
          if(speed[c-1] > limit[b-1]){
            ans = speed[c-1] - limit[b-1];
          }
        }
      }
    }
    ans = max(ans, temp);
    temp = ans;
    ans = 0;
  }
  fout << temp;
}
