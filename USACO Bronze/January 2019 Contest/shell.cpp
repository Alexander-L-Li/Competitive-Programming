#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("shell.in");
  ofstream fout("shell.out");
  int n, pebble, ans = 0, temp = 0; fin >> n; int swap1[n], swap2[n], guess[n];
  for(int i=0; i<n; i++){
    fin >> swap1[i] >> swap2[i] >> guess[i];
  } 
  for(int a=1; a<=3; a++){
    pebble = a;
    for(int b=0; b<n; b++){
      if(pebble == swap1[b]){
        pebble = swap2[b];
      } else if (pebble == swap2[b]){
        pebble = swap1[b];
      }
      if(pebble == guess[b]){ ans += 1; }
    }
    ans = max(ans, temp);
    temp = ans;
    ans = 0;
  }
  fout << temp;
}
