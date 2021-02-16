void solve() {
	int n, i, j;
	cin >> n;
	vi A(n);
	cin >> A;
	mii freq;
	for (int& x : A)
		freq[x]++;
	vi V;
	for (auto& [x, y] : freq)
		V.EB(y);
	ll ans = INF;
	sort(all(V));
	for (i = 0; i < sz(V); i++)
		cmin(ans, 0LL + n - (0LL + sz(V) - i) * V[i]);
	print(ans);
}
 
