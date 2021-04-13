void solve() {
	int n, q, t;
	cin >> n >> q;
	vi A(n), ord;
	cin >> A;
	vvi col(51);
	for (int i = 0; i < n; i++)
		if (!sz(col[A[i]]))
			col[A[i]].EB(i);
 
	while (q--) {
		cin >> t;
		int i, j;
		print(col[t][0] + 1);
		f1(i, 50)
			if (sz(col[i]) && col[i] < col[t])
				col[i][0]++;
			col[t][0] = 0;
	}
}
