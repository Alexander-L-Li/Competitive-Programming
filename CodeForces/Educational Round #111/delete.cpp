#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  for(int z=0; z<t; z++){
    int n, a, b; string s; cin >> n >> a >> b >> s;
    int m = unique(s.begin(), s.end()) - s.begin();
    cout << n * a + max(n * b, (m / 2 + 1) * b) << '\n'; 
  }
}

// unique function returns the amount of consecutive distinct chars
// (m/2 + 1) tells us the minimum amount of operations it will take
// we want to find the maximum added on value that b can give us
