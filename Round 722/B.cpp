void solve() {
	int i, n, u, v;
	cin >> n;
	vl A(n);
	cin >> A;
	sort(all(A));
	ll mxi = n - 1;
 
	for (i = 0; i < mxi; i++) {
		if (A[i + 1] - A[i] < A[mxi])
			mxi--, i--;
	}
	print(mxi + 1);
}
