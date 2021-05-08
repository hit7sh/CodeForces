 
void solve() {
	string s;
	int n, i;
	cin >> n >> s;
	vi pos;
	f0(i, n) if (s[i] == '*') pos.EB(i);
	if (sz(pos) == 0) print(0);
	else {
		int k = pos[sz(pos) / 2];
		ll ans = 0;
		for (int& x : pos)
			ans += abs(x - k);
		f0(i, sz(pos)) ans -= abs(i - sz(pos) / 2);
		print(ans);
	}
}
 
