#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int n;
char arr[MAXN][MAXN];
int row[] = {0, 1, 0, -1};
int col[] = {1, 0, -1, 0};

bool dfs(int xstart, int ystart, int xend, int yend){
    set<char> check;
    queue<pair<int,int>> q;
    int count = 0;
    int conts[26];
    for(int a=0; a<26; a++){
        conts[a] = 0;
    }
    int visited[MAXN][MAXN];
    for(int a=xstart; a<=xend; a++){
        for(int b=ystart; b<=yend; b++){
            visited[a][b] = -1;
        }
    }
    for(int a=xstart; a<=xend; a++){
        for(int b=ystart; b<=yend; b++){
            if(visited[a][b] < 0){
                q.push(make_pair(a, b));
                conts[arr[a][b] - 'A']++;
                visited[a][b] = count;
                check.insert(arr[a][b]);
                while(!q.empty()){
                    pair<int, int> p = q.front();
                    q.pop();
                    for(int c=0; c<4; c++){
                        int xx = p.first + row[c];
                        int yy = p.second + col[c];
                        if(xx <= xend && xx >= xstart && yy <= yend && yy >= ystart && arr[xx][yy] == arr[a][b] && visited[xx][yy] < 0){
                            q.push(make_pair(xx, yy));
                        } 
                        if(xx <= xend && xx >= xstart && yy <= yend && yy >= ystart && arr[xx][yy] == arr[a][b]){
                            visited[xx][yy] = count;
                        }
                    }
                }
                count++;
            }
        }
    }
    // for(int a=xstart; a<=xend; a++){
    //     for(int b=ystart; b<=yend; b++){
    //         cout << visited[a][b];
    //     } cout << endl;
    // }
    if(check.size() == 2 && count >= 3){
        auto it = next(check.begin(), 0);
        auto it2 = next(check.begin(), 1);
        if(conts[*it - 'A'] == 1 || conts[*it2 - 'A'] == 1){
            return true;
        }
    }
    return false;
}

int main() {
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    cin >> n;
    for(int a=0; a<n; a++){
        for(int b=0; b<n; b++){
            cin >> arr[a][b];
        }
    }
    vector<pair<int, int>> v;
    vector<pair<int, int>> v2;
    for(int a=0; a<n; a++){
        for(int b=0; b<n; b++){
            bool check = false;
            for(int c=n-1; c>=0; c--){
                for(int d=n-1; d>=0; d--){
                    if(dfs(a, b, c, d)){
                        v.push_back(make_pair(a, b));
                        v2.push_back(make_pair(c, d));
                    }
                }
            }
        }
    }
    set<string> s;
    if(v.size() == 0){
        cout << 0;
    } else {
        int ans = 0;
        for(int a=0; a<v.size(); a++){
            bool check = false;
            for(int b=0; b<v.size(); b++){
                if(a != b && v[a].first >= v[b].first && v[a].second >= v[b].second && v2[a].first <= v2[b].first && v2[a].second <= v2[b].second){
                    check = true;
                } 
            }
            if(!check){
                ans++;
                string str = to_string(v[a].first) + to_string(v[a].second) + to_string(v2[a].first) + to_string(v2[a].second);
            }
        }
        cout << ans;
    }
}
