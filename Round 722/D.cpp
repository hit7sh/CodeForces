int cnt[mxN];
ll ans[mxN];
 
void solve() {
	int i, n, u, v;
	cin >> n;
	print(ans[n]);
}
 
 
 
signed main() { 
	cout << fixed << setprecision(12);
	cnt[0] = 1;
	for (int i = 1; i < mxN; i++) {
		for (int j = i; j < mxN; j += i)
			cnt[j]++;
	}
 
	ll sm = 0;
	ans[1] = 1;
	for (int i = 2; i < mxN; i++) {
		sm += cnt[i - 1];
		ans[i] = (cnt[i] + sm) % mod;
		cnt[i] = ans[i];
	}
 
	__speed() solve();
	 // int t, i; for (cin >> t, i = 1; i <= t; i++) cout << "Case #" << i << ": ", solve();
}
