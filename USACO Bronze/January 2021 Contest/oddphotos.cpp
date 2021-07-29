#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n; 
    vector<int> arr(n); int even = 0, odd = 0;
    for(int a=0; a<n; a++){
        cin >> arr[a];
        if(arr[a] % 2 == 0){
            even++;
        } else if(arr[a] % 2 != 0){
            odd++;
        }
    }
    int count = 0;
    while(odd > 0){
        if(count % 2 == 0 && even > 0){
            even--;
        } else if(count % 2 == 0 && even <= 0){
            odd -= 2;
        } 
        if(count % 2 != 0){
            odd--;
        }
        count++;
    }
    if(odd < 0){
        cout << count - 2;
    } else if(even > 0){
        cout << count + 1;
    } else {
        cout << count;
    }
}
