void solve() {
	int n;
	cin >> n;
	vl A(n);
	cin >> A;
	bool ok = 1;
	ll has = 0;
	for (int i = 0; i < n; i++) {
		has += max(0ll, A[i] - i);
		if (A[i] < i) {
			ll req = i - A[i];
			if (has < req)
				ok = 0;
			else
				has -= req;
		}
		A[i] = i;
	}
	Yes(ok);
}
