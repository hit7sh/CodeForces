void solve() {
	int n;
	cin >> n;
	vector<double> A(n);
	cin >> A;
	sort(all(A));
	double sm = 0;
	int ans = -INF;
	for (int i = 0; i < n; i++) {
		sm += A[i];
		cmax(ans, n - int(UB(all(A), sm / (i + 1)) - A.begin()));
	}
	print(ans);
 
}
