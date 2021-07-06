#include <iostream>
#include <fstream>

using namespace std;
int main() {
  ifstream fin("billboard.in");
  ofstream fout("billboard.out");
  int bx1, bx2, by1, by2, fx1, fx2, fy1, fy2, count = 0;
  fin >> bx1 >> by1 >> bx2 >> by2 >> fx1 >> fy1 >> fx2 >> fy2;
  bx1 = min(bx1, bx2); bx2 = max(bx1,bx2); by1 = min(by1,by2); by2 = max(by1, by2);
  fx1 = min(fx1,fx2); fx2 = max(fx1, fx2); fy1 = min(fy1, fy2); fy2 = max(fy1, fy2);
  int b = bx2 - bx1;
  int h = by2 - by1;
  if(fx1 <= bx1 && fx2 >= bx2){
    if(fy1 >= by1){
      h = by1 - fy1;
    } else if (fy2 <= by2){
      h = by2 - fy2;
    }
  }
  if(fy1 <= by1 && fy2 >= by2){
    if(fx1 >= bx1){
      b = bx1 - fx1;
    } else if (fx2 <= bx2){
      b = bx2 - fx2;
    }
  } 
    fout << abs(b*h);
}
