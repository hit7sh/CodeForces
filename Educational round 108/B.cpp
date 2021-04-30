int dp[101][101];
int n, m, k;
int f(int x, int y, int rem) {
	if (rem < 0) return 0;
	if (x == n && y == m)
		return rem == 0;
	if (dp[x][y] != -1) return dp[x][y];
	int& ans = dp[x][y] = 0;
	if (x < n) ans |= f(x + 1, y, rem - y);
	if (y < m) ans |= f(x, y + 1, rem - x);
	return ans;
}
void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> k;
	Yes(f(1, 1, k));
}	
