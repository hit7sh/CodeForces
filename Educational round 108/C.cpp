void solve() {
	int n, i;
	cin >> n;
	vvi A(n);
	vl a(n), b(n), ans(n);
	cin >> a >> b;
	f0(i, n) {
		A[a[i] - 1].EB(b[i]);
	}
	f0(i, n) sort(rall(A[i]));
	f0(i, n) {
		int m = A[i].size();
		if (!m) continue;
		vl pref(m);
		pref[0] = A[i][0];
		for (int j = 1; j < A[i].size(); j++)
			pref[j] = pref[j - 1] + A[i][j];
		for (int j = 1; j <= m; j++) {
			ans[j - 1] += pref[m / j * j - 1];
		}
	}
 
	print(ans);
}	
