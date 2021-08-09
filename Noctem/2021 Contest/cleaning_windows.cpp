//Teammate Jerry Li's Code:

#include <iostream>
#include <fstream>
#include <set>
using namespace std;

long long N,K;
long long dirty[int(1e5)];


bool check(long long a){
    multiset<long long> m;
    long long sum = 0;

    for(long long i = 0; i < a; i++){
        m.insert(dirty[i]);
        sum += dirty[i];
    }
    if(sum + a-1 <= K){
        return true;
    }
    
    for(long long i = a ; i < N; i++){
        if(dirty[i] < *(m.rbegin())){
            sum -= *(m.rbegin());
            sum += dirty[i];
            m.erase(--m.end());
            m.insert(dirty[i]);
            if(sum + i <= K){
                return true;
            }
        }
    }

    return false;
}

int main(){
    ifstream fin ("windows.in");
    ofstream fout ("windows.out");

    
    fin >> N >> K;

    for(long long i = 0 ; i < N; i++){
        fin >> dirty[i];
    }

    long long pos = 0; long long max = N;
    for(long long a = max; a >= 1; a /= 2){
        while(check(pos+a)) pos += a;
    }

    fout << pos;


    fin.close();
    fout.close();
}
