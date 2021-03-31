const int N = 2e5 + 5;
vi pr;
vi lp(N + 1);
ll ans = 1, n;
map<int, map<int, int>> mp, cnt;
 
 
void solve(int p, int v) {
	while (lp[v] > 1) {
		mp[p][lp[v]]++;
		cnt[lp[v]][mp[p][lp[v]]]++;
		if (cnt[lp[v]][mp[p][lp[v]]] == n)
			ans = ans * lp[v] % mod;
		v /= lp[v];
	}
}
 
void solve() {
	for (int i = 2; i <= N; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.PB(i);
		}
		for (int j = 0; j < sz(pr) && pr[j] <= lp[i] && i * pr[j] <= N; j++)
			lp[i * pr[j]] = pr[j];
	}
 
	int q, v, p, i;
	cin >> n >> q;
	f0(i, n) {
		cin >> v;
		solve(i + 1, v);
	}
	f0(i, q) {
		cin >> p >> v;
		solve(p, v);
		print(ans);
	}
}
 
