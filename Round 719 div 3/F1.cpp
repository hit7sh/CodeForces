int query(int l, int r) {
	#ifndef ONLINE_JUDGE
	int ans = 0;
	for (int i = l; i <= r; i++) ans += A[i];
		return ans;
	#else
	cout << '?' << ' '  << l << ' ' << r << endl;
	int a;
	cin >> a;
	return a;
	#endif
}
 
void solve() {
	int n, t, k;
	cin >> n >> t;
	cin >> k;
	int L = 1, R = n, M;
	while (L < R) {
		M = (L + R) / 2;
		// print(L, M, R);
		if (M - query(1, M) >= k)
			R = M;
		else
			L = M + 1;
	}
	cout << '!' << ' ' << L;
}
 
 
