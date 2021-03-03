void solve() {
	int n, A, B, C, D, a, b, c, d;
	cin >> n >> A >> B >> C >> D;
	bool ok = 0;
	for (int mask = 0; mask < (1 << 4); mask++) {
		a = A, b = B, c = C, d = D;		
		if (mask & (1 << 0))
			a--, b--;
		if (mask & (1 << 1))
			b--, c--;
		if (mask & (1 << 2))
			c--, d--;
		if (mask & (1 << 3))
			d--, a--;
		if (a >= 0 && b >= 0 && c >= 0 && d >= 0 && a < n - 1 && b < n - 1 && c < n - 1 && d < n - 1)
			ok = 1;
	}
	Yes(ok);
}
