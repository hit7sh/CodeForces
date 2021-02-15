void solve() {
	int n, i, j;
	cin >> n;
	if (n&1) {
		f0(i, n*(n-1)/2)
			cout << (i&1?-1:1) << ' ';
		cout << endl;
	} else {
		map<pii, int> mp;
		f1(i, n) {
			mp[{i, i+1}] = 0, i++;
		}
		f1(i, n)
			for (j = i+1; j <= n; j++) {
				if (mp.count({i, j}))
					cout << 0 << ' ';
				else if ((i+j)&1)
					cout << -1 << ' ';
				else 
					cout << 1 << ' ';
			}
			cout << endl;
 
	}
}
