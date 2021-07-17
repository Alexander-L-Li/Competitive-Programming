#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  for(int a=0; a<t; a++){
    int h, w; cin >> h >> w;
    int arr[101][101];
    for(int b=0; b<101; b++){
      for(int c=0; c<101; c++){
        arr[b][c] = 0;
      }
    }
    for(int b=0; b<h; b++){
      for(int c=0; c<w; c++){
        if((b == 0 || b == h-1 || c == 0 || c == w-1)){
          if(arr[b+1][c+1] != 1 && arr[b-1][c+1] != 1 && arr[b-1][c-1] != 1 && arr[b+1][c-1] != 1 && arr[b][c+1] != 1 && arr[b][c-1] != 1 && arr[b+1][c] != 1 && arr[b-1][c] != 1)
            arr[b][c] = 1;
        } 
      } 
    }
    int sum = 0;
    for(int b=0; b<h; b++){
      for(int c=0; c<w; c++){
          cout << arr[b][c];
      }
      cout << "\n";
    }
    cout << "\n";
  }
}
