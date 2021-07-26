#include <iostream>
#include <vector>

using namespace std;
int ans[2000];

void friday(int milk, vector<int>a1, vector<int>a2){
    for(int a=0; a<a2.size(); a++){
        ans[milk + a2[a]] = 1;
    }
}

void thursday(int milk, vector<int>a1, vector<int>a2){
    for(int a=0; a<a1.size(); a++){
        vector<int> newA2 = a2; newA2.push_back(a1[a]);
        vector<int> newA1 = a1; newA1.erase(newA1.begin()+a);
        friday(milk-a1[a], newA1, newA2);
    }
}

void wednesday(int milk, vector<int>a1, vector<int> a2){
    for(int a=0; a<a2.size(); a++){
        vector<int> newA1 = a1; newA1.push_back(a2[a]);
        vector<int> newA2 = a2; newA2.erase(newA2.begin()+a);
        thursday(milk+a2[a], newA1, newA2);
    }
}

void tuesday(int milk, vector<int>a1, vector<int>a2){
    for(int a=0; a<a1.size(); a++){
        vector<int> newA2 = a2; newA2.push_back(a1[a]);
        vector<int> newA1 = a1; newA1.erase(newA1.begin()+a);
        wednesday(milk-a1[a], newA1, newA2);
    }
}

int main(){
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    vector<int> arr(10); vector<int> arr2(10); 
    int sol = 0;
    for(int a=0; a<10; a++){
        cin >> arr[a];
    }
    for(int a=0; a<10; a++){
        cin >> arr2[a];
    }
    tuesday(1000, arr, arr2);
    for(int a=0; a<2000; a++){
        if(ans[a] == 1){
            sol += 1;
        }
    }
    cout << sol;
}
