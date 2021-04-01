const int N = 5005;
ll dp[N][N];
int n, k, q, v;
 
ll f(int i, int rem) {
	if (i < 0 or i >= n)
		return 0;
	if (rem == 0)
		return 1;
	ll &ans = dp[i][rem];
	if (~ans)
		return ans;
	ans = (f(i - 1, rem - 1) + f(i + 1, rem - 1)) % mod;
	return ans;
}
 
void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> k >> q;
	vl A(n), co(n);
	cin >> A;
	int i;
	ll ans = 0;
	for (i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++)
			co[i] = (co[i] + f(i, j) * f(i, k - j) % mod) % mod;
		ans = (ans + co[i] * 1ll * A[i] % mod) % mod;
	}
	// dbg(co);
	while (q--) {
		cin >> i >> v;
		--i;
		ll dif = (v - A[i] + mod) % mod;
		ans = (ans + dif * co[i]) % mod;
		A[i] = v;
		print(ans);
	}
}
