#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("cownomics.in");
  ofstream fout("cownomics.out");
  int n, m, ans = 0; fin >> n >> m; char pos[n*m*2];
  bool equal = false;
  for(int i=0; i<n*m*2; i++){
    fin >> pos[i];
  }
  for(int a=0; a<m; a++){
    for(int b=a; b<n*m+a; b+=m){
      for(int c=n*m+a; c<n*2*m; c+=m){
        cout << pos[b] << pos[c] << a << "\n";
        if(pos[b] == pos[c]){
          equal = true;
        }
      }
    }
    if(equal == false){
      ans += 1;
    }
    equal = false;
  }
  fout << ans;
}
