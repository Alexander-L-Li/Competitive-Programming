#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("cowsignal.in");
  ofstream fout("cowsignal.out");
  int m, n, k; fin >> m >> n >> k;
  char arr[m*n];
  string temp = "";
  char ans[(m*k)*(n*k)];
  for(int a=0; a<m*n; a++){
    fin >> arr[a];
  }
  for(int a=0; a<=m*n; a++){
    if(a % n == 0 && a != 0){
      fout << "\n";
      for(int b=0; b<k-1; b++){
        fout << temp << "\n";
      } 
      temp = ""; 
      if(a == m*n){
        break;
      }
    } 
    for(int b=0; b<k; b++){
      ans[a + b] = arr[a];
      temp += arr[a];
      fout << ans[a+b];
    }   
  }
}
