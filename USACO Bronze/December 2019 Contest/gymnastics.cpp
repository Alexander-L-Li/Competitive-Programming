#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	int k, n;
	cin >> k >> n;
	int ans = 0;
	int arr[k * n];
	vector<int> p1, p2;

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < k; b++) {
			cin >> arr[k * a + b];
		}
	}
	for (int a = 0; a < k; a++) {
		for (int b = 0; b < n; b++) {
			for (int c = b; c < n; c++) {
				if (c != b) {
					p1.push_back(arr[a * n + b]);
					p2.push_back(arr[a * n + c]);
				}
			}
		}
	}
	int count = 0;
	for(int a = 0; a < p1.size() / k; a++) {
		for(int b = p1.size() / k; b < p1.size(); b++) {
			if(p1[a] == p1[b] && p2[a] == p2[b]) {
				count += 1;
        //cout << p1[a] << " " << p2[a] << "\n";
			}
		}
		if (count == k-1) {
			ans += 1;
		}
		count = 0;
	}

	for (int a = 0; a < p1.size(); a++) {
		//cout << p1[a] << " " << p2[a] << "\n";
	}
	cout << ans;
}
