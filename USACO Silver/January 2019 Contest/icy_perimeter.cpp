#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1002;

int n;
char arr[MAXN][MAXN];
int row[] = {-1, 0, 1, 0};
int col[] = {0, 1, 0, -1};
int perimeter = 0;
int area = 0;

int dfs(int x, int y) {
  int count = 0;
  arr[x][y] = '-';
  for (int a = 0; a < 4; a++) {
    int xx = x + row[a];
    int yy = y + col[a];
    if (xx <= n && xx >= 1 && yy <= n && yy >= 1 && arr[xx][yy] == '#') {
      count += dfs(xx, yy) + 1;
    } else if (xx <= n + 1 && xx >= 0 && yy <= n + 1 && yy >= 0 &&
               arr[xx][yy] == '.') {
      perimeter++;
    }
  }
  return count;
}

int main() {
  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);
  cin >> n;
  for (int a = 1; a <= n; a++) {
    arr[a][0] = '.';
    arr[a][n + 1] = '.';
    for (int b = 1; b <= n; b++) {
      cin >> arr[a][b];
      arr[n + 1][b] = '.';
      arr[0][b] = '.';
    }
  }
  int p = 0;
  for (int a = 1; a <= n; a++) {
    for (int b = 1; b <= n; b++) {
      if (arr[a][b] == '#') {
        int x = dfs(a, b) + 1;
        if (x > area) {
          area = x;
          p = perimeter;
        } else if (x == area && perimeter < p) {
          p = perimeter;
        } 
        perimeter = 0;
      }
    }
  }
  cout << area << " " << p;
}
