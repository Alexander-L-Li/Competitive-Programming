#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("mixmilk.in");
  ofstream fout("mixmilk.out");
  long long c1, m1, c2, m2, c3, m3, pour = 0;
  fin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
  for(int a=0; a<4; a++){
    pour += 1;
    if(pour == 1 || pour == 4){
      if(m2 + m1 > c2){
        m1 = abs(m1 + m2 - c2);
        m2 = c2;
      } else if (m2 + m1 <= c2) { 
        m2 += m1; m1 = 0; 
      }
    } else if(pour == 2){
      if(m3 + m2 > c3){
        m2 = abs(m2 + m3 - c3);
        m3 = c3;
      } else if (m3 + m2 <= c3){ 
        m3 += m2; m2 = 0;
        }
    } else if (pour == 3){
      if(m1 + m3 > c1){
        m3 = abs(m1 + m3 - c1);
        m1 = c1;
      } else if (m1 + m3 <= c1) { 
        m1 += m3; m3 = 0; 
        }
    }
  } 
  fout << m1 << "\n" << m2 << "\n" << m3;
}
