#include <iostream>

using namespace std;

int n, m; int S[500][50], P[500][50], A[64];
string plain[500], spotty[500];

bool check(int i, int j, int k){
  bool diff = true;
  for(int a=0; a<n; a++){
    A[S[a][i]*16 + S[a][j]*4 + S[a][k]] = 1;
  }
  for(int a=0; a<n; a++){
    if(A[P[a][i]*16 + P[a][j]*4 + P[a][k]]){
      diff = false;
    }
  }
  for(int a=0; a<n; a++){
    A[S[a][i]*16 + S[a][j]*4 + S[a][k]] = 0;
  }
  return diff;
}

int main() {
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);
  int ans = 0; cin >> n >> m;
  for(int a=0; a<n; a++){
    cin >> spotty[a];
    for(int b=0; b<m; b++){
      if(spotty[a][b] == 'A')
        S[a][b] = 0;
      if (spotty[a][b] == 'C')
        S[a][b] = 1;
      if (spotty[a][b] == 'G')
        S[a][b] = 2;
      if (spotty[a][b] == 'T')
        S[a][b] = 3;
      } 
    }
  for(int a=0; a<n; a++){
    cin >> plain[a];
    for(int b=0; b<m; b++){
      if(plain[a][b] == 'A')
        P[a][b] = 0;
      if (plain[a][b] == 'C')
        P[a][b] = 1;
      if (plain[a][b] == 'G')
        P[a][b] = 2;
      if (plain[a][b] == 'T')
        P[a][b] = 3;
    }
    }
  for(int i=0; i<m; i++){
    for(int j=i+1; j<m; j++){
      for(int k=j+1; k<m; k++){
        if(check(i, j, k)){
          ans += 1;
        }
      }
    }
  }
  cout << ans;
}
