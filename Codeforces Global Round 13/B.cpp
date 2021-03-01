void solve() {
	int n, i;
	ll u, v;
	cin >> n >> u >> v;
	vi A(n);
	cin >> A;
	bool ok = 0;
	for (i = 1; i < n; i++) {
		if (abs(A[i] - A[i-1]) > 1)
			ok = 1;
	}
	if (ok) {
		print(0);
		return;
	}
	ll ans = LINF;
 
	for (i = 1; i < n; i++) {
		if (abs(A[i] - A[i-1]) == 1) {
			if (A[i] > A[i-1]) {
				if(A[i] + 1 <= int(1e6+1) && !(i == n-1 && A[i] + 1 == int(1e6+1)))
					ans = min(ans, v);
				if (A[i-1] - 1 >= 0 && !(i-1 == 0 && A[i-1] -1 == 0))
					ans = min(ans, v);
				ans = min(ans, u);
			} else {
				if (A[i] - 1 >= 0)
					ans = min(ans, v);
				if (A[i-1] + 1 <= int(1e6+1))
					ans = min(ans, v);
				ans = min(ans, u);
			}
		} else {
			ans = min(ans, u+v);
			if (A[i] - 2 >= 0 or A[i] + 2 <= int(1e6+1))
				ans = min(ans, 2*v);
		}
	}
	print(ans);
}
 
