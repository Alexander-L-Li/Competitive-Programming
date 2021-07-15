#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;
  for(int a=0; a<t; a++){
    int b = 0; int s; cin >> s;
    while(b*b < s){
      b += 1;
    }
    cout << b << "\n";
  }
}
