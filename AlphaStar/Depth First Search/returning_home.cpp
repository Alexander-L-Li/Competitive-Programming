#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 5001;

vector<int> adj[MAXN];
vector<string> ans;
vector<int> ans2;
bool visited[MAXN];
int n, ns, h;

void dfs(int a, int depth, string s){
    if(a == h && depth+1 > ans.size()){
      ans2.push_back(depth+1);
      string temp = "";
      for(int a=0; a<s.size(); a++){
        if(s[a] != ' '){
          temp += s[a];
        } else {
          ans.push_back(temp);
          temp = "";
        }
      }
      return;
    }
    visited[a] = true;
    for(int v : adj[a]){
        if(!visited[v]){
            dfs(v, depth+1, s + to_string(a) + ' ');
        }
    }
}

int main(){
    cin >> n >> ns >> h;
    for(int i=0; i<ns; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[a].push_back(c);
    }
    dfs(1, 0, "");  
    int depth = ans2[ans2.size()-1]; 
    cout << depth << endl;
    for(int a=ans.size()-depth+1; a<ans.size(); a++){
      cout << ans[a] << endl;
    }
    cout << h;
}
