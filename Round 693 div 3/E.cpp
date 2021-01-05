#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	for (cin >> t; t--; ) {
		int i, n, h, w;
		cin >> n;
		vector<int> ans(n, -1);
		vector<array<int, 3>> D;

		for(i = 0; i < n; i++) {
			cin >> w >> h;
			D.push_back({w, -h, i});
			D.push_back({h, -w, i});
		}

		sort(D.begin(), D.end());
		int e=-1, m=2e9;

		for (auto &x:D) {
			w = x[0];
			h = -x[1];
			int id = x[2];

			if (h > m) {
				ans[id] = e+1;
			} else if (h < m) {
				m = h;
				e = id;
			}
		}

		for (int& x:ans)
			cout << x << ' ';
		cout << endl;
	}
    return 0;
}
