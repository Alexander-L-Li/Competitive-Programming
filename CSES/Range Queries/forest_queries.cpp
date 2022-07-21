#include <iostream>

using namespace std;
const int MAXN = 1000;
int arr[MAXN + 1][MAXN + 1];
int pref[MAXN + 1][MAXN + 1];

int main(){
    int n, q; cin >> n >> q; 
    for(int a=0; a<n; a++){
        for(int b=0; b<n; b++){
            char c; cin >> c;
            if(c=='*')
            arr[a+1][b+1]++;
        }
    }
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            pref[a][b] = arr[a][b] + pref[a-1][b] + pref[a][b-1] - pref[a-1][b-1];
        }
    }
    for (int a = 0; a < q; a++) {
		int from_row, to_row, from_col, to_col;
		cin >> from_row >> from_col >> to_row >> to_col;
		cout << pref[to_row][to_col]
				- pref[from_row - 1][to_col]
				- pref[to_row][from_col - 1]
				+ pref[from_row - 1][from_col - 1] << '\n';
	}

}
