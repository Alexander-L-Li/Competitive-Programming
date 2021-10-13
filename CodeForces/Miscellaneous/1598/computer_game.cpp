#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    int n; cin>>n;
    char arr[2][n];
    for(int a=0; a<2; a++){
        for(int b=0; b<n; b++){
            cin>>arr[a][b];
        }
    }
    for(int a=0; a<n; a++){
        if(arr[0][a]==arr[1][a] && arr[0][a] == '1'){
            cout<<"NO";
            return; 
        }
    }
    cout << "YES";
}
int main(){
    int t; cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
}
