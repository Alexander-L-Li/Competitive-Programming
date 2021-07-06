#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream fin("outofplace.in");
  ofstream fout("outofplace.out");
  int N, temp = 0, ans = 0, odd = 0, dupe = 0, temp3 = 0, temp2 = 0, temp4 = 0, sub = 0, ans2 = 0; 
  fin >> N;
  int order [N+1], copy[N];
  for(int i=0; i<N; i++){
    fin >> order[i];
    copy[i] = order[i];
  }
  order[N] = 1000001;
  for(int i=0; i<N; i++){
    if(order[i] < temp2 && order[i] < order[i+1]){
      sub = 0;
      odd = i;
      temp3 = 0;
      for(int a=odd; a>=1; a--){
      if(order[a] <= order[a+1] && order[a] >= order[a-1]){
        ans = ans - (sub);
        break;
      }
      temp = order[a];
      order[a] = order[a-1];
      if(order[a-1] == temp4){
       sub += 1;
      }
      temp4 = order[a-1];
      order[a-1] = temp;
      ans += 1;
      }
      for(int a=0; a<N; a++){
        if((order[a] > temp3 && order[a] > order[a+1]) || (order[a] < temp3 && order[a] < order[a+1])){
          ans = 0;
        } 
        temp3 = order[a];
      }
    } else if(order[i] > temp2 && order[i] > order[i+1]){
      odd = i;
      sub = 0;
      temp3 = 0;
      for(int a=odd; a<N-1; a++){
      if(order[a] <= order[a+1] && order[a] >= order[a-1]){
        ans2 = ans2 - (sub);
        break;
      }
      temp = order[a];
      order[a] = order[a+1];
      if(order[a] == temp4){
        sub += 1;
      }
      temp4 = order[a];
      order[a+1] = temp;
      ans2 += 1;
    }
      for(int a=0; a<N; a++){
        if((order[a] > temp3 && order[a] > order[a+1]) || (order[a] < temp3 && order[a] < order[a+1])){
          ans2 = 0;
        } 
        temp3 = order[a];
      }
    }
    for(int a=0; a<N; a++){
      order[a] = copy[a];
    }
    temp2 = order[i];
  }
  if(ans != 0){
    fout << ans;
  } else if(ans2 !=0){
    fout << ans2;
  }
} 
