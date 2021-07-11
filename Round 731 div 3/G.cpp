void solve() {
  int n, m;
  cin >> n >> m;
  vvi g(n), rg(n);
  vi self;
 
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    if (x == y) self.EB(x);
    g[x].EB(y);
    rg[y].EB(x);
  }
 
  vi r(n), vis(n), ans(n), T, C, SCC = self;
 
  function<void(int)> dfs1 = [&](int u) {
    vis[u] = 1;
    for (int v : g[u])
      if (!vis[v])
        dfs1(v);
    T.EB(u);
  };
  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs1(i);
    if (i == 0) r = vis;
  }
  reverse(all(T));
  vis = vi(n, 0);
 
  function<void(int)> dfs2 = [&](int u) {
    vis[u] = 1;
    C.EB(u);
    for (int v : rg[u])
      if (!vis[v])
        dfs2(v);
  };
 
  for (int i : T) {
    if (!vis[i]) {
      C = vi();
      dfs2(i);
      if (sz(C) > 1) SCC.insert(SCC.end(), all(C));
    }
  }
  vis = vi(n, 0);
 
  function<void(int)> dfs3 = [&](int u) {
    ans[u]++;
    for (int v : g[u])
      if (ans[v] < 2)
        dfs3(v);
  };
  dfs3(0);
 
  queue<int> q;
  for (int x : SCC) if (r[x]) q.push(x);
 
  while (!q.empty()) {
    int tp = q.front(); q.pop();
    vis[tp] = 1;
    ans[tp] = -1;
 
    for (int x : g[tp])
      if (!vis[x])
        q.push(x);
  }
  print(ans);
}
