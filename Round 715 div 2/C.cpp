ll dp[2001][2001];
vl A;
 
ll f(int l, int r) {
	if (l == r) return 0;
	ll &ans = dp[l][r];
	if (~ans) return ans;
	return ans = (A[r] - A[l]) + min(f(l + 1, r), f(l, r - 1));
}
void solve() {
	int n, i, j;
	memset(dp, -1 ,sizeof(dp));
	cin >> n;
	A.resize(n);
	cin >> A;
	vl dp(n + 1);
	sort(all(A));
	print(f(0, n - 1));
}
 
 
