#include <iostream>
#include <fstream>

using namespace std; 

int main(){
  ifstream fin("lifeguards.in");
  ofstream fout("lifeguards.out");
  int N, ans = 0, sub = 0, temp = 0; fin >> N;
  bool overlap = false;
  int start[N], end[N];
  for(int i=0; i<N; i++){
    fin >> start[i] >> end[i];
  }
     for(int a=0; a<N; a++){
       for(int b=0; b<N; b++){
         if(b == a){
           continue;
         } else {
           for(int c=0; c<N; c++){
             if(end[b] > start[c] && end[b] < end[c] && c != a){
              sub += abs(end[b] - start[c]);
             } 
           }
           temp += abs(end[b] - start[b]);
         }
       }
        ans = max(temp - sub, ans); 
        sub = 0;
        temp = 0;
     }
     fout << ans;
  }
