#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;
  string ans[t];
  for(int a=0; a<t; a++){
    int k, n, m; cin >> k >> n >> m;
    int arr[n], arr2[m]; vector <int> v; bool done = false; int count = 0; v.clear();
    int tn = 0, tm = 0;
    for(int b=0; b<n; b++){
      cin >> arr[b];
    }
    for(int b=0; b<m; b++){
      cin >> arr2[b];
    }
    for(int b=0; b<n; ++b){
      if(arr[b] == 0){
        v.push_back(0);
      } else if(arr[b] > 0 && arr[b] > tn){
        v.push_back(arr[b]);
        tn = arr[b];  
        count += 1;
      } else {
        done = true;
      }
    }
    for(int b=0; b<m; ++b){
      if(arr[b] == 0){
        v.push_back(0);
      } else if(arr[b] > 0 && arr[b] > tm){
        v.push_back(arr[b]);
        tm = arr[b];
        count += 1;
      } else {
        done = true;
      }
    }
    string s = "";
    for(int b=0; b<v.size(); b++){
      s += to_string(v[b]);
    }
    ans[a] = s;
  }
  for(int a=0; a<t; a++){
    cout << ans[a] << "\n";
  }
}
