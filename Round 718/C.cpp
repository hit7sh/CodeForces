void solve() {
	int n, m, r, i, j;
	cin >> n;
	vi P(n);
	cin >> P;
	vvi ans(n, vi(n));
	f0(i, n) {
		int x = i, y = i, z = P[i];
		ans[x][y] = P[i];
		while (--z) {
			if (y > 0 && !ans[x][y - 1])
				y--;
			else x++;
			ans[x][y] = P[i];
		}
	}
	f0(i, n)
		f0(j, i + 1)
			cout << ans[i][j] << " \n"[j == i];
}
