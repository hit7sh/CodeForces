vector<vector<int>> kosaraju(int n, vector<pair<int, int>>& edges) { // 0 indexed
  int m;
  m = edges.size();
  vector<vector<int>> g(n), rg(n), SCC;
  vector<int> self;
 
  for (auto [x, y] : edges) {
    if (x == y) self.push_back(x);
    g[x].push_back(y);
    rg[y].push_back(x);
  }
  if (self.size() > 0) SCC.push_back(self);
  vector<int> r(n), vis(n), ans(n), toposort, C;
 
  function<void(int)> dfs_topsort = [&](int u) {
    vis[u] = 1;
    for (int v : g[u])
      if (!vis[v])
        dfs_topsort(v);
    toposort.push_back(u);
  };
  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs_topsort(i);
    if (i == 0) r = vis;
  }
 
  reverse(toposort.begin(), toposort.end());
  vis = vector<int>(n, 0);
 
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    C.push_back(u);
    for (int v : rg[u])
      if (!vis[v])
        dfs(v);
  };
 
  for (int i : toposort) {
    if (!vis[i]) {
      C = vector<int>();
      dfs(i);
      if (C.size() > 0) // excluding single node without self loop
        SCC.push_back(C); 
    }
  }
  SCC.EB(toposort);
  return SCC;
}
 
void solve() {
  int n;
  cin >> n;
  vvi adj(n);
  int k;
  vector<pii> E;
  f0(i, n) {
    cin >> k;
    int x;
    while (k--) {
      cin >> x;
      E.EB(i, x - 1);
      adj[i].EB(x - 1);
    }
  }
  
  vvi SCC = kosaraju(n, E);
  vi topo = SCC.back();
  SCC.pop_back();
  
  if (sz(SCC) != n) {
    print(-1);
  } else {
    int c = 0;
    vi dp(n, 1);
    reverse(all(topo));
    for (int u : topo) {
      for (int v : adj[u]) {
        if (v < u) cmax(dp[u], dp[v]);
        else cmax(dp[u], 1 + dp[v]);
      }
    }
    print(*max_element(all(dp)));
  }
}
 
