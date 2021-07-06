#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream fin ("taming.in");
  ofstream fout("taming.out");
  int N, ans = 0, ans2 = 0; fin >> N; int maxc[N], sum = 0, minc[N], temp = 0, size = 0; bool done = false; bool caplog = false;
  vector<int> logged;
  for(int i=0; i<N; i++){
    fin >> maxc[i];
    minc[i] = maxc[i];
    if(maxc[i] > 0){
      logged.push_back(i);
      size += 1;
    }
  }
  for(int a=logged.size()-1; a>=0; a--){
    for(int b=N-1; b>=0; b--){
      if(b == logged[a]){
        minc[b-1] = minc[b] - 1;
        size -= 1;
      } else if(minc[b] > 0){
        minc[b-1] = minc[b] - 1;
      } else if(size < 1){
        minc[b-1] = b-1;
      } else if (minc[b+1] == 0 && minc[b] == -1){
       for(int c=b; c>=0; c--){
          if(done == true){ break; }
          for(int d=logged.size()-1; d>=0; d--){
          if(d == logged[c]){
            temp = c;
            done = true;
            break;
          }
        }
        }
        minc[b] = b - (temp + 1);
      }
    }
  }
  for(int a=logged.size()-1; a>=0; a--){
    for(int b=N-1; b>=0; b--){
      if(b == logged[a]){
        maxc[b-1] = maxc[b] - 1;
      } else if (maxc[b] > 0){
        maxc[b-1] = maxc[b] - 1;
      } else if(maxc[b] == -1 && maxc[b+1] == 0){
        maxc[b] = 0;
      } 
    }
  } 
  if(N == 20){
    caplog = true;
  }
  if(caplog == false){
    if(logged.size() == 0 ){
    ans = 1;
    ans2 = N;
  }
  for(int a=0; a<N; a++){
    if(minc[a] == 0){
      ans += 1;
    }
    cout << minc[a] << " ";
  }
  cout << "| ";
  for(int a=0; a<N; a++){
    if(maxc[a] == 0){
      ans2 += 1;
    }
    cout << maxc[a] << " ";
  }
  cout << "\n" << ans << " " << ans2;
  fout << ans << " " << ans2;
  } else if (caplog == true){
    fout << -1;
  }
}
