void solve() {
	int n, i, j;
	cin >> n;
	
	vl X(n), Y(n);
 
	f0(i, n) cin >> X[i] >> Y[i];
	sort(all(X));
	sort(all(Y));
	if (n & 1) {
		print(1);
		return;
	}
	print((X[n / 2] - X[n / 2 - 1] + 1)*(Y[n / 2] - Y[n / 2 - 1] + 1));
}
 
