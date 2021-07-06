#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("square.in");
  ofstream fout("square.out");
  int ax1, ax2, ay1, ay2, b, h, ans;
  int bx1, bx2, by1, by2;
  fin >> ax1 >> ay1 >> ax2 >> ay2  >> bx1 >> by1 >> bx2 >> by2;
  b = max(max(ax1, ax2), max(bx1, bx2)) - min(min(ax1, ax2), min(bx1, bx2));
  h = max(max(ay1, ay2), max(by1, by2)) - min(min(ay1, ay2), min(by1, by2));
  ans = max(b,h) * max(b,h);
  fout << ans;
}
