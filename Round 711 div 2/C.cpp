void solve() {
	int n, k, i;
	cin >> n >> k;
	vi A(n - 1, 1);
	int ans = 1;
	if (k >= 2)
		ans += n;
	k--;
	for (int i = 0; i < k - 1; i++) {
		if (i & 1) {
			for (int j = 1; j < n - 1; j++)
				A[j] = (A[j] + A[j - 1]) % mod;
		} else {
			for (int j = n-3; j >= 0; --j) {
				A[j] = (A[j] + A[j + 1]) % mod;
			}
		}
		for (auto& x : A)
			ans = (ans + x) % mod;
	}
	print(ans);
}
