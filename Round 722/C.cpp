void solve() {
	int i, n, u, v;
	cin >> n;
	vector<pair<ll, ll>> A(n + 1);
	f1(i, n) cin >> A[i];
 
	vvi adj(n + 1);
	f0(i, n - 1) {
		cin >> u >> v;
		adj[u].EB(v);
		adj[v].EB(u);
	}
	ll dp[n + 1][2];
 
	function<void(int, int)> dfs = [&](int u, int p) {
		dp[u][0] = dp[u][1] = 0;
 
		for (int v : adj[u]) {
			if (v != p) {
				dfs(v, u);
				dp[u][0] += max(dp[v][0] + abs(A[u].F - A[v].F), dp[v][1] + abs(A[u].F - A[v].S));
				dp[u][1] += max(dp[v][0] + abs(A[u].S - A[v].F), dp[v][1] + abs(A[u].S - A[v].S));
			}
		}
	};
	dfs(1, -1);
	print(max(dp[1][0], dp[1][1]));
}
 
 
