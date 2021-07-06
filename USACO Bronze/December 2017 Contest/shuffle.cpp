#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream fin("shuffle.in");
  ofstream fout("shuffle.out");
  int N; fin >> N;
  int cows[N];
  int ids[N];
  int tids[N];
  int pos[N];
  
  for(int i=1; i<=N; i++){
    fin >> cows[i-1];
    pos[i-1] = i;
  } 
  for(int i=0; i<N; i++){
    fin >> ids[i];
  }
  
  for(int i=0; i<3; i++){
    for(int a=1; a<=N; a++){
      for(int b=1; b<=N; b++){
        if(pos[a-1] == cows[b-1]){
          tids[b-1] = ids[a-1];
        }
      }
    }
    for(int c=0; c<N; c++){
      ids[c] = tids[c];
      if(i == 2){
        fout << tids[c] << "\n";
      }
    }
  }
}
