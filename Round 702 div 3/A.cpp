void solve() {
	int n, i;
	cin >> n;
	vi A(n);
	cin >> A;
	ll ans = 0;
	f0(i, n-1) {
		int mx = max(A[i], A[i+1]), mn = min(A[i], A[i+1]);
		while (2*mn < mx) {
			mn = 2*mn;
			ans++;
		}
	}
	print(ans);
}
