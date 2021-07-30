#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    int n; cin >> n;
    vector<pair<string, string>> orders;
    string cows[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    string csort[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    string ans[8];
    int same = 0;
    for(int a=0; a<n; a++){
        string arr[6];
        for(int b=0; b<6; b++){
            cin >> arr[b];
        }
        orders.push_back(make_pair(arr[0], arr[5]));
    }
    do{
        int count = 0;
        
        for(int a=0; a<orders.size(); a++){
            for(int b=0; b<8-1; b++){
                if((orders[a].first == cows[b] && orders[a].second == cows[b+1]) || (orders[a].second == cows[b] && orders[a].first == cows[b+1])){
                    count++;
                }
            }
        }
        if(count == n){
            int temp = 0;
            for(int a=0; a<8; a++){
                for(int b=0; b<8; b++){
                    if(cows[a] == csort[b]){
                        temp++;
                    }   
                }
            }
            if(temp > same){
                for(int a=0; a<8; a++){
                    ans[a] = cows[a];
                }
            }
            same = max(same, temp);
        }
        
    } while(next_permutation(cows, cows+8));

    for(int a=0; a<8; a++){
        cout << ans[a] << "\n";
    }
}
