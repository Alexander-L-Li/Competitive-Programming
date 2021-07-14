#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;
  for(int i=0; i<t; i++){
    int n, a, b; cin >> n >> a >> b;
    string temp; int MAX = -999999999;
    string arr[n];
    cin >> temp;
    for(int j=0; j<n; j++){ 
      arr[j] = temp[j];
    } 
    int tmax = 0; int s = 0;
    int count = 0;
    int c1 = 0, c2 = 0;
    string last; 
    for(int d=0; d<n; d++){
      if(arr[d] == "0"){
        c1 += 1;
      } else if(arr[d] == "1"){
        c2 += 1;
      }
      if(last != arr[d] && d != 0){
        s += count* a + b;
        count = 0;
      }
      count += 1;
      last = arr[d];
    }
    MAX = max(s, MAX);
    MAX = max(n*(1 * a + b), MAX);
    MAX = max((c1 * a + b) + (c2 * a + b), MAX);
    cout << MAX << "\n";
  }
}
