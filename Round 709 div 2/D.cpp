void solve() {
	queue<int> q;
	int n;
	cin >> n;
	vi A(n), vis(n), nxt(n), ans;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		nxt[i] = (i+1)%n;
		q.emplace(i);
	}
	while (!q.empty()) {
		int f = q.front();
		q.pop();
 
		if (!vis[f] && gcd(A[f], A[nxt[f]]) == 1) {
			vis[nxt[f]] = 1;
			ans.EB(nxt[f] + 1);
			nxt[f] = nxt[nxt[f]];
			q.emplace(f);
		}
	}
	print(sz(ans), ans);
}	
