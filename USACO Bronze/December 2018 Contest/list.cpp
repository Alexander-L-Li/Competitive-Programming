#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin ("blist.in");
  ofstream fout ("blist.out");
  int n, ans = 0, curr; fin >> n;
  int start[n], end[n], buck[n];
  for(int i=0; i<n; i++){
    fin >> start[i] >> end[i] >> buck[i];
  } 
  for(int clock=0; clock<=1000; clock++){
    curr = 0;
    for(int a=0; a<n; a++){
      if(clock >= start[a] && clock <= end[a]){
        curr += buck[a];
      }
    }
    ans = max(ans, curr);
  }
  fout << ans;
}
