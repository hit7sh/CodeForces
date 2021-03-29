void solve() {
	int n, W, i, c = 0;
	cin >> n >> W;
	vi A(n);
	cin >> A;
	vi f(20);
	for (int& x : A)
		f[int(log2(x))]++;
	
	sort(all(A));
	ll sm = 0;
	for (i = n-1; ~i; --i) {
		if (!f[int(log2(A[i]))]) continue;
		c++;sm = 0;
		while (f[int(log2(A[i]))] && sm + A[i] <= W) {
			sm += A[i], f[int(log2(A[i]))]--;
		}
		if (W - sm) {
			for (int j = 19; ~j; --j) {
				while (f[j] && (1LL << j) + sm <= W)
					sm += 1 << j, f[j]--;
			}
		}
	}
	print(c);
}
