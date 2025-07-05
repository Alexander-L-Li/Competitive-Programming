#include <iostream>
#include <cmath>
using namespace std;

struct customer{
    long long numcookie, nummuffin, twait, ineq;
};
customer arr[100];


long long N, tcookie, tmuffin;
bool check(long long k){
    long long xlo = 0; long long xhi = tcookie-1; //tcookie is the 7, tmuffin is 9, numcookie is 4, nummuffin is 3
    for(int i = 0; i < N; i++){
        if(arr[i].numcookie > arr[i].nummuffin){
            xlo = max((long long)ceil(double(arr[i].ineq - arr[i].nummuffin * k)/double(arr[i].numcookie - arr[i].nummuffin)), xlo);
        }
        else if(arr[i].numcookie < arr[i].nummuffin){
            xhi = min((long long)floor(double(arr[i].ineq - arr[i].nummuffin * k)/double(arr[i].numcookie - arr[i].nummuffin)), xhi); //maybe something sus here
        }
        else{
            if(k * arr[i].numcookie < arr[i].ineq){
                return false;
            }
        }
        if(xlo > xhi){
            return false;
        }
    }
    if(k - xlo < 0 || k - xhi >= tmuffin){ //check dis 
        return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> N >> tcookie >> tmuffin;
        for(int i = 0; i < N; i++){
            cin >> arr[i].numcookie >> arr[i].nummuffin >> arr[i].twait;
            arr[i].ineq = tcookie * arr[i].numcookie + tmuffin * arr[i].nummuffin - arr[i].twait;

            //4(7-x) + 3(9-y) <= 18
        }

        long long minsum = 0;
        long long maxsum = tcookie+tmuffin-2; //check here something might be wrong

        while(minsum < maxsum){
            if(check((minsum + maxsum)/2)){
                maxsum = (minsum + maxsum)/2;
            }
            else{
                minsum = (minsum + maxsum)/2 + 1;
            }
        }

        cout << maxsum << endl;


    }

}
