void solve() {
  int n;
  cin >> n;
  vvi adj(n + 1);
  int u, v;
  f0(i, n - 1) {
    cin >> u >> v;
    adj[u].EB(v);
    adj[v].EB(u);
  }
 
  vector<bool> leaf(n + 1), is_bud(n + 1);
  for (int i = 2; i <= n; i++) {
    if (adj[i].size() == 1) leaf[i] = 1;
  }
 
 
  function<bool(int, int)> dfs = [&](int u, int p) {
    bool bud = 1;
    int bc = 0, lc = 0;
    for (int v : adj[u]) if (p ^ v) {
      if (leaf[v]) lc += 1;
      else if (dfs(v, u)) bc++; else lc++; 
    }
    is_bud[u] = !!lc;
    if (!is_bud[u]) leaf[u] = 1;
    return is_bud[u];
  };
 
  dfs(1, 0);
  int budcount = 0;
  for (int i = 2; i <= n; i++) {
    if (is_bud[i]) budcount++;
  }
  int root_leaf = 0;
  for (int x : adj[1]) if (leaf[x]) root_leaf = 1;
  print(n - 2 * budcount - root_leaf);
    // cout << '\n';
}
