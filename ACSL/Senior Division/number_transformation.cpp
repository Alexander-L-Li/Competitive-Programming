#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, p; cin >> n >> p;
  string s = to_string(n);
  p = s.length()-p;
  vector<long long> v; 
    for(long long a=0; a<p; a++){
      long long x = (s[p]-'0') + (s[a]-'0');
      v.push_back(x);
    }
  set<long long> v2;
   while(n % 2 == 0) {
        v2.insert(2);
        n = n/2;
    }
    for (long long a = 3; a <= sqrt(n); a+=2) {
        while (n % a == 0) {
            v2.insert(a);
            n = n/a;
        }
    }
    if (n > 2){
        v2.insert(n);
    }
    
   v.push_back(v2.size());

  for(long long a=p+1; a<s.length(); a++){
    v.push_back(abs((s[p] - '0') - (s[a]-'0')));
  }
  for(long long a=0; a<v.size(); a++){
    cout << v[a];
  }
}
