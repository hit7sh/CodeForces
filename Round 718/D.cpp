void solve() {
	int n, m, k, r, i, j;
	cin >> n >> m >> k;
	vvi H(n, vi(m - 1)), V(n - 1, vi(m));
	cin >> H >> V;
	if (k & 1) {
		f0(i, n) f0(j, m) cout << -1 << " \n"[j == m - 1];
	} else {
		vector<vector<vector<int64_t>>> dp(k / 2 + 1, vector<vector<int64_t>>(n, vector<int64_t>(m, 0)));
		int steps;
		f1(steps, k/2) {
			f0(i, n) f0(j, m) {
				dp[steps][i][j] = INF;
				if (i > 0) cmin(dp[steps][i][j], dp[steps - 1][i - 1][j] + 2*V[i - 1][j]);
				if (j > 0) cmin(dp[steps][i][j], dp[steps - 1][i][j - 1] + 2*H[i][j - 1]);
				if (i < n - 1) cmin(dp[steps][i][j], dp[steps - 1][i + 1][j] + 2*V[i][j]);
				if (j < m - 1) cmin(dp[steps][i][j], dp[steps - 1][i][j + 1] + 2*H[i][j]);
			}
		}
	f0(i, n) f0(j, m) cout << dp[k/2][i][j] << " \n"[j == m - 1];
	}
}
 
