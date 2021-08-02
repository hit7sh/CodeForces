void solve() {
  int n, k;
  cin >> n >> k;
  vvi adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].EB(v);
    adj[v].EB(u);
  }
 
  if (k == 2) {
    print(n * (n - 1) / 2);
    return;
  }
 
  ll ans = 0;
  for (int cen = 0; cen < n; cen++) {
    queue<int> q;
    vi id(n);
    vi dep(n, -1);
    dep[cen] = 0;
    q.push(cen);
    while (sz(q)) {
      int par = q.front(); q.pop();
      for (int x : adj[par]) {
        if (~dep[x]) continue;
        q.push(x);
        dep[x] = 1 + dep[par];
        if (par == cen)
          id[x] = x;
        else
          id[x] = id[par];
      }
    }
    vvi freq(n, vi(n));
    for (int i = 0; i < n; i++) {
      if (cen ^ i) {
        freq[dep[i]][id[i]] += 1;
      }
    }
    for (int d = 0; d < n; d++) {
      vl dp(k + 1);
      dp[0] = 1;
      for (int v = 0; v < n; v++) {
        if (freq[d][v] > 0) {
          for (int i = k; i > 0; i--) 
            dp[i] = (dp[i] + freq[d][v] * dp[i - 1] % mod) % mod;
        }
      }
      ans = (ans + dp[k]) % mod;
    }
  }
    print(ans);
}
