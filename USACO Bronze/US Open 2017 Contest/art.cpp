#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
  ifstream fin("art.in");
  ofstream fout("art.out");
  int n, ans = 0, temp, minX = 101, maxX = 0, minY = 101, maxY = 0, base, height, count = 0; 
  fin >> n; char pos[n*n]; vector<char> colors, check, bad;
  vector<char> ansX, ansY;
  bool seen = false;
  for(int i=0; i<n*n; i++){
    fin >> pos[i];
    if(pos[i] != '0'){
      for(int j=0; j<colors.size(); j++){
        if(colors[j] == pos[i]){
          seen = true;
        }
      }
      if (seen == false){
        colors.push_back(pos[i]);
      }
      seen = false;
    }
  }
  seen = false;
  for(int a=0; a<colors.size(); a++){
    for(int x=1; x<=n; x++){
      for(int y=1; y<=n; y++){
        if(colors[a] == pos[(y-1)*n + (x-1)]){
          minX = min(minX, x); maxX = max(maxX, x);
          minY = min(minY, y); maxY = max(maxY, y);
        }
      }
    }
    check.push_back(colors[a]);
    ansX.push_back(minX); ansX.push_back(maxX); ansY.push_back(minY); ansY.push_back(maxY);
    minX = 101, maxX = 0, minY = 101, maxY = 0;
  }
  for(int a=0; a<check.size(); a++){
	  for(int x=1; x<=n; x++){
        for(int y=1; y<=n; y++){
          if(check[a] == pos[(y-1)*n + (x-1)]){
            for(int b=0; b<ansX.size()/2; b++){
              if(b != a && x >= ansX[b*2] && x <= ansX[b*2+1] && y >= ansY[b*2] && y <= ansY[b*2+1]){
              for(int i=0; i<bad.size(); i++){
                if(check[a] == bad[i]){
                  seen = true;
                }
              }
              if(seen == false){
                bad.push_back(check[a]);
              }
              seen = false;
             }
            }
          }
        }
      }
    }
  fout << colors.size() - bad.size();
}
