#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
int main(){
  long long n;
  cin >> n;
  long long check = n/2;
  vector<long long> even;
  vector<long long> odd;
  for(int i=1; i<=n; i++){
    if(i % 2 == 0){
      even.push_back(i);
    } else if (i % 2 != 0){
      odd.push_back(i);
    }
  }
  for(int i=1; i<=n; i++){
    if(i <= check && n > 3){
      cout << even[i-1] << " ";
    } else if (i > check && n > 3){
      cout << odd[i-(check + 1)] << " ";
    } else if (n == 1){
      cout << 1;
    } else {
      cout << "NO SOLUTION";
      break;
    }
  }
}
