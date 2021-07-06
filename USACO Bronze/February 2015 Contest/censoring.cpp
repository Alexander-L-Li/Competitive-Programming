#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);
	string s;
	cin >> s;
	string sub;
	cin >> sub;
	int size = s.size();
	int size2 = sub.size();
	string ans;
	for(int i = 0; i < size; i++) {
		ans += s[i];
		if(ans.size() > size2 && ans.substr(ans.size() - size2) == sub){
			ans.resize(ans.size() - size2);
		}
	}
	cout << ans;
}
