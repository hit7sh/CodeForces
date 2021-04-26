void solve() {
	int n, k, i;
	cin >> n >> k;
	vi A(n + 1), pre(n + 1), mn(n + 1);
	f1(i, n) cin >> A[i];
	function<bool(int)> check = [&](int median) {
		f1(i, n)
			pre[i] = A[i] >= median ? 1 : -1;
		f1(i, n)
			pre[i] += pre[i - 1], mn[i] = min(mn[i - 1], pre[i]);
		for (i = k; i <= n; i++) {
			if (pre[i] > mn[i - k])
				return 1;
		}
		return 0;
	};
	int L = 1, R = n, M;
	while (L < R) {
		M = (L + R + 1) / 2;
		if (check(M))
			L = M;
		else R = M - 1;
	}
	print(L);
}	 
 
