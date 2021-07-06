#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream fin("lostcow.in");
  ofstream fout("lostcow.out");
  int x, y, type = 1, sum = 1, count = 0, temp = 0; fin >> x >> y;
  bool less = false, more = false;
  if(x < y){
    less = true;
  } else if (x > y){
    more = true;
  }
  while(true){
    if(type % 2 != 0){
      x += sum + temp;
    } else if (type % 2 == 0){
      x -= sum + temp;
    }
    count += sum + temp;
    temp = sum;
    sum = sum * 2;
    type += 1;
    if(less == true && x >= y){
      fout << count - (x - y);
      break; 
    } else if (more == true && x <= y){
      fout << count - abs(x - y);
      break;
    }
  }
}
