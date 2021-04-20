void solve() {
	int n, i;
	cin >> n;
	vi ans;
	ll p = 1;
	f1(i, n - 1)
		if (gcd(i, n) == 1)
			ans.EB(i), p = p * i % n;
	if (p == n - 1 && n != 2)
		ans.pop_back();
	print(sz(ans));
	print(ans);
}
 
