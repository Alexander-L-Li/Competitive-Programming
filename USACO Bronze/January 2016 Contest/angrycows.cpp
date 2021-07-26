#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int n; vector<long long> v(n);
int ans = 0;

int right(int pos){
  int time = 1; int count = 0;
  int next = 0; int temp = 0;
  for(int a=pos; a<n; a++){
    for(int b=a+1; b<n; b++){
      if(v[b] - v[a] <= time){
        count++;
        next = max(next, b);
      } 
    }
    if(temp == next){
      return count;
    }
    temp = next;
    a = next - 1;
    time++;
  }
  return count;
}

int left(int pos){
 int time = 1; int count = 0;
 int temp = 0; int next = 10000;
  for(int a=pos; a>=0; a--){
    for(int b=a-1; b>=0; b--){
      if(v[a] - v[b] <= time){
        count++;
        next = min(next, b);
      }
    }
    if(temp == next){
      return count;
    }
    temp = next;
    a = next + 1;
    time++;
  }
  return count;
}

int main() {
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);
  cin >> n; int ans = 0;
  v.resize(n);
  for(int a=0; a<n; a++){ cin >> v[a]; }
  sort(v.begin(), v.end());
  for(int a=0; a<n; a++){
    int count = 1;
    if(a == 0 && v[a+1] - v[a] == 1){
      count += right(a);
    } else if (a == n-1 && v[a] - v[a-1] == 1){
      count += left(a);
    } else {
      if(v[a+1] - v[a] == 1){
        count += right(a);
      }
      if(v[a] - v[a-1] == 1){
        count += left(a);
      }
    }
    ans = max(ans, count);
  }
  cout << ans;
}
