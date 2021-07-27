#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  long long N;
  cin >> N;
  while(true){
    cout << N << " ";
  if(N==1){
    break;
   }
  if(N % 2 != 0){
    N = N*3 + 1;
  } else if(N % 2 == 0){
    N = N/2;
  }
 }
}
