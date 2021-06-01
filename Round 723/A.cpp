void solve() {
	int n;
	cin >> n;
	n *= 2;
	vi A(n);
	cin >> A;
	sort(all(A));
	vi ans;
	for (int i = 0; i < n / 2; i++)
		ans.EB(A[i]), ans.EB(A[n - i - 1]);
	print(ans);
}
 
