#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("cbarn.in");
  ofstream fout("cbarn.out");
  int n, mult = 1, count = 0, ans = 999999999, temp = 0; fin >> n;
  int room[n];
  for(int i=0; i<n; i++){
    fin >> room[i];
  }
  for(int a=0; a<n; a++){
    for(int b=a; b<=n; b++){
      if(a == b){
        if(a == n-1){
          b = -1;
        }
        continue;
      } else {
        if(count == n-1){
          break;
        }
        temp += mult * room[b];
        mult += 1;
        if(b == n-1 && count != n-1){
          b = -1;
        }
        count += 1;
      }
    }
    mult = 1;
    count = 0;
    ans = min(ans, temp);
    temp = 0;
  }
  fout << ans;
}
