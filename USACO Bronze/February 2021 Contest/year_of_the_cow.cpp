#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <map>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<char, char> pc;
typedef pair<string, string> ps;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef multiset<string> mss;
typedef queue<int> qi;
typedef queue<ll> qll;
typedef queue<string> qs;
typedef set<int> si;
typedef set<ll> sll;
typedef set<string> ss;
typedef set<char> sc;

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F1R(i, a) for (int i=1; i<(a); i++)
#define mp make_pair
#define pb push_back
#define f first
#define sec second
#define ub upper_bound
#define lb lower_bound

int n;
string arr[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
map<string, int> bday;

string check(int year){ 
    int a = 0, b = 2021;
    string s;
    while(b < year){
        a++; b++;
        if(a == 12){
            a = 0;
        }
    }   
    while(b > year){
        a--; b--;
        if(a == -1){
            a = 11;
        }
    }
    return arr[a];
}

void solve(){
    cin >> n;
    bday["Bessie"] = 2021;
    string cowA, born, in, type, animal, year, from, cowB;
    F0R(a, n){
        cin >> cowA >> born >> in >> type >> animal >> year >> from >> cowB;
        bday[cowA] = bday[cowB];
        do{
            if(type == "previous"){
                bday[cowA]--;
            } else {
                bday[cowA]++;
            }
        } while(check(bday[cowA]) != animal);
    }
    int ans = bday["Bessie"] - bday["Elsie"];
    cout << abs(ans);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    //cin >> t;
    while(t--){
        solve();
    }
}
