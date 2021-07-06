#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
  ifstream fin("measurement.in");
  ofstream fout("measurement.out");
  int N, ans = 0, count = 0, cap = 0; fin >> N;
  int day[N], change[N], b = 7, m = 7, e = 7, mostM = 0;
  string cows[] = {"Bessie, Mildred, Elsie"}, temp;
  string name[N], pogairCow = "";
  char type[N];
  for(int i=0; i<N; i++){
    fin >> day[i] >> name[i] >> type[i] >> change[i];
    cap = max(day[i], cap);
  }
  while(count != N){
    for(int i=1; i<=cap; i++){
      for(int j=0; j<N; j++){
        if(i == day[j]){
          count += 1;
          if(type[j] == '+'){
            if(name[j] == "Bessie"){
              b += change[j];
            } else if (name[j] == "Mildred"){
              m += change[j];
            } else if (name[j] == "Elsie"){
              e += change[j];
            }
          } else if (type[j] == '-'){
            if(name[j] == "Bessie"){
              b -= change[j];
            } else if (name[j] == "Mildred"){
              m -= change[j];
            } else if (name[j] == "Elsie"){
              e -= change[j];
            }
          }

          mostM = max(max(b, m), max(m, e));
          temp = pogairCow;
          pogairCow = "";
            if(mostM == b && (b == e || b == m)){
              pogairCow += "Bessie";
            } else if (mostM == b){
              pogairCow = "Bessie";
            }
            if(mostM == m && (m == b || m == e)){
              pogairCow += "Mildred";
            } else if (mostM == m){
              pogairCow = "Mildred";
            }
            if(mostM == e && (e == b || e == m)){
              pogairCow += "Elsie";
            } else if (mostM == e){
              pogairCow = "Elsie"; 
            }
          if(pogairCow != temp){
            ans += 1;
          }
        }
      }
    }
  }
  fout << ans;
}
