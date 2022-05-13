#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string blocks[4];

bool check(vector<int> v){
    sort(v.begin(), v.end());
    for(int a=0; a<v.size(); a++){
        //cout << v[a];
    } //cout << endl;
    for(int a=0; a<v.size()-1; a++){
        if(v[a] == v[a+1]){
            return false;
        }
    }
    return true;
}

bool solve(){
    string word; cin >> word;
    vector<vector<int>> perms(word.length());
    for(int b=0; b<word.length(); b++){ 
        for(int c=0; c<4; c++){ 
            for(int d=0; d<blocks[c].length(); d++){ 
                if(word[b] == blocks[c][d]){
                    perms[b].push_back(c);
                    break;
                }
            }
        }
    }
    vector<vector<int>> arr(word.length());
    int p = 0;
    for(int a=4; a>=0; a--){
        for(int b=0; b<word.length(); b++){
            if(perms[b].size() == a){
                arr[p] = perms[b];
                p++;
            }
        }
    }
    vector<int> v; 
    for(int b=0; b<arr[0].size(); b++, v.pop_back()){
        if(word.length() > 1){
            v.push_back(arr[0][b]);
            for(int c=0; c<arr[1].size(); c++, v.pop_back()){
                v.push_back(arr[1][c]);
                if(word.length() > 2){
                    for(int d=0; d<arr[2].size(); d++, v.pop_back()){
                        v.push_back(arr[2][d]);
                        if(word.length() > 3){
                            for(int e=0; e<arr[3].size(); e++){
                                v.push_back(arr[3][e]);
                                if(check(v)){
                                    return true;
                                }
                                v.pop_back();
                            }
                        } else {
                            if(check(v)){
                                return true;
                            } 
                        }
                    }
                } else {
                    if(check(v)){
                        return true;
                    } 
                }
            }
        } else {
            return true;
        }
    }
    return false;
}
int main(){
    int n; cin >> n;
    cin >> blocks[0] >> blocks[1] >> blocks[2] >> blocks[3];
    while(n--){
        if(solve()){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
}
