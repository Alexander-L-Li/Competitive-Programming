#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("teleport.in");
  ofstream fout("teleport.out");
  int a, b, x, y, ans = 101;
  fin >> a; fin >> b; fin >> x; fin >> y;
  ans = min(ans, abs(a-b)); 
  ans = min(ans, abs(a-y) + abs(b-x)); 
  ans = min(ans, abs(a-x) + abs(b-y));
  fout << ans;
}
