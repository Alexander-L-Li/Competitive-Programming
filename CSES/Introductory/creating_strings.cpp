#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
typedef long long ll;
 
 
int main(){
    string s; int n; 
    vector<string> v;
    cin >> s; n = s.length();
    sort(s.begin(), s.end());
    do{
        v.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
    cout << v.size() << "\n";
    for(int a=0; a<v.size(); a++){
        cout << v[a] << "\n";
    }
}
