#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;
  while(t--){
    int k, n, m; cin >> k >> n >> m; int arr[n], arr2[m];
    for(int b=0; b<n; b++){
      cin >> arr[b];
    }
    for(int b=0; b<m; b++){
      cin >> arr2[b];
    }
    vector <int> ans; int p1 = 0, p2 = 0;
    bool done = false;
    while(p1 != n || p2 != m){
      if(p1 != n && arr[p1] == 0){ 
          ans.push_back(0);
          p1++; k++;
      } else if(p2 != m && arr2[p2] == 0){
          ans.push_back(0);
          p2++; k++;
      } else if(p1 != n && arr[p1] <= k){
          ans.push_back(arr[p1++]);
      } else if(p2 != m && arr2[p2] <= k){
          ans.push_back(arr2[p2++]);
      } else {
          cout << -1;
          done = true;
          break;
      }
    }

    if(!done){
      for(int b=0; b<ans.size(); b++){
        cout << ans[b] << " ";
      }
    }
    cout << "\n";
  }
  
}
