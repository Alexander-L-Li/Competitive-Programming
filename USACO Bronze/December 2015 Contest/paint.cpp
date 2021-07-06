#include <iostream>
#include <fstream>

using namespace std;
int main() {
  ifstream fin("paint.in");
  ofstream fout("paint.out");
  int a, b, c, d, ans; fin >> a >> b >> c >> d;
  a = min(a,b); b = max(a,b); c = min(c,d); d = max(c,d);
  if((c >= a && c <= b) && (d >= a && d <= b)){
    ans = b-a;
  } else if (a >= c && a <= d && b >= c && b <= d){
    ans = d-c;
  } else if ((c < a || c > b) && (d < a || d > b)){
    ans = (b-a) + (d-c);
  } else if(c <= a && d >= a && d <= b){
    ans = b - c;
  } else if (d >= b && c >= a && c <= b){
    ans = d - a;
  } 
  fout << ans;
}
