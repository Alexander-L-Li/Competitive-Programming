#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
using namespace std;

#define ll long long

int main(){
  ifstream fin("billboard.in");
  ofstream fout("billboard.out");
  int ans = 0;
  int x1, y1, x2, y2, b1x1, b1x2, b1y1, b1y2, b2x1, b2x2, b2y1, b2y2;
  int h, w;
  for(int i=0; i<3; i++){
    fin >> x1; fin >> y1; fin >> x2; fin >> y2;
    if( i== 0){ b1x1 = x1, b1x2 = x2, b1y1 = y1; b1y2 = y2; }
    else if (i == 1){ b2x1 = x1, b2x2 = x2; b2y1 = y1; b2y2 = y2; }
    else { break; }
    h = abs(y1-y2) ; w = abs(x1 - x2);
    ans += h*w;
  }

  for(int i=0; i<2; i++){
    if(i == 0){
    if(x1 >= min(b1x1,b1x2) && x1 <= max(b1x1,b1x2)){ 
      if(x2 <= max(b1x1,b1x2) && x2 >= min(b1x1,b1x2)){
        w = abs(x2-x1);
      } else if (x2 > max(b1x1,b1x2)){
        w = max(b1x1,b1x2) - x1;
      }
     } else if (x2 >= min(b1x1, b1x2) && x2 <= max(b1x1, b1x2)){
      if(x1 <= max(b1x1, b1x2) && x1 >= min(b1x1, b1x2)){
        w = abs(x2-x1);
      } else if (x1 > max(b1x1, b1x2)){
        w = x2 - min(b1x1, b1x2);
      } else if (x1 < min(b1x1, b1x2)){
          w = x2 - min(b1x1, b1x2);
        }
     } else if ((x1 <= min(b1x1, b1x2) && x2 >= max(b1x1,b1x2)) || (x2 <= min(b1x1, b1x2) && x1 >= max(b1x1, b1x2))){
      w = abs(b1x1 - b1x2);   
    } else {
      w = 0;
    }
    if(y1 >= min(b1y1,b1y2) && y1 <= max(b1y1,b1y2)){ 
      if(y2 <= max(b1y1,b1y2) && y2 >= min(b1y1,b1y2)){
        h = abs(y2-y1);
      } else if (y2 > max(b1y1,b1y2)){
        h = max(b1y1,b1y2) - y1;
      }
     } else if (y2 >= min(b1y1, b1y2) && y2 <= max(b1y1, b1y2)){
      if(y1 <= max(b1y1, b1y2) && y1 >= min(b1y1, b1y2)){
        h = abs(y2-y1);
      } else if (y1 > max(b1y1, b1y2)){
        h = y2 - min(b1y1, b1y2);
      } else if (y1 < min(b1y1, b1y2)){
          h = y2 - min(b1y1, b1y2);
        }
     } else if ((y1 <= min(b1y1, b1y2) && y2 >= max(b1y1,b1y2)) || (y2 <= min(b1y1, b1y2) && y1 >= max(b1y1, b1y2))){
      h = abs(b1y1 - b1y2);  
     } else {
       h = 0;
     }

    } else if (i == 1){
      if(x1 >= min(b2x1,b2x2) && x1 <= max(b2x1,b2x2)){ 
        if(x2 <= max(b2x1,b2x2) && x2 >= min(b2x1,b2x2)){
          w = abs(x2-x1);
        } else if (x2 > max(b2x1,b2x2)){
          w = max(b2x1,b2x2) - x1;
        }
      } else if (x2 >= min(b2x1, b2x2) && x2 <= max(b2x1, b2x2)){
        if(x1 <= max(b2x1, b2x2) && x1 >= min(b2x1, b2x2)){
          w = abs(x2-x1);
        } else if (x1 > max(b2x1, b2x2)){
          w = x2 - min(b2x1, b2x2);
        } else if (x1 < min(b2x1, b2x2)){
          w = x2 - min(b2x1, b2x2);
        }
      } else if ((x1 <= min(b2x1, b2x2) && x2 >= max(b2x1,b2x2)) || (x2 <= min(b2x1, b2x2) && x1 >= max(b2x1, b2x2))){
        w = abs(b2x1 - b2x2);
      } else {
        w = 0;
      }

      if(y1 >= min(b2y1,b2y2) && y1 <= max(b2y1,b2y2)){ 
      if(y2 <= max(b2y1,b2y2) && y2 >= min(b2y1,b2y2)){
        h = abs(y2-y1);
      } else if (y2 > max(b2y1,b2y2)){
        h = max(b2y1,b2y2) - y1;
      }
     } else if (y2 >= min(b2y1, b2y2) && y2 <= max(b2y1, b2y2)){
      if(y1 <= max(b2y1, b2y2) && y1 >= min(b2y1, b2y2)){
        h = abs(y2-y1);
      } else if (y1 > max(b2y1, b2y2)){
        h = y2 - min(b2y1, b2y2);
      } else if (y1 < min(b2y1, b2y2)){
          h = y2 - min(b2y1, b2y2);
        }
     } else if ((y1 <= min(b2y1, b2y2) && y2 >= max(b2y1,b2y2)) || (y2 <= min(b2y1, b2y2) && y1 >= max(b2y1, b2y2))){
      h = abs(b2y1 - b2y2);  
     } else {
       h = 0;
     }
    } 
    ans -= w*h;
  }
  fout << ans;
}
