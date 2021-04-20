#include<bits/stdc++.h>
using namespace std;

string ans;
bool solvefor(string& a, string& b, char code) {
	int n = a.length(), i = 0, j = 0; ans = "";

	for (; i < n && j < n;) {
		while (i < n && a[i] != code) ans += a[i++];
		if (i == n) break;
		while (j < n && b[j] != code) ans += b[j++];
		if (j == n) break;
		if (a[i] == b[j]) ans += a[i++], j++;
		else ans += a[i++];
	}
	while (i < n) ans += a[i++];
	while (j < n) ans += b[j++];
	return (int)ans.size() <= n / 2 * 3;
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<string> s(3);
		cin >> s[0] >> s[1] >> s[2];
		vector<int> order = {0, 1, 2};
		do {
			if (solvefor(s[order[0]], s[order[1]], '0')) {
				cout << ans << endl;
				break;
			} else if (solvefor(s[order[0]], s[order[1]], '1')) {
				cout << ans << endl;
				break;
			}
		} while (next_permutation(order.begin(), order.end()));
		
	}
	return 0;
}
