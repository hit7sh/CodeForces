void solve() {
  int n, i;
  cin >> n;
  vi A(n), B(n);
  cin >> A >> B;
 
  vi ida(n + 1), idb(n + 1);
  f0(i, n) {
    ida[A[i]] = i;
    idb[B[i]] = i; 
  }
 
  vvi adj(n + 1);
  f0(i, n) {
    adj[i].EB(idb[A[i]]);
    adj[i].EB(ida[B[i]]);
  }
  vi vis(n);
 
  int c = 0;
  function<void(int)> dfs = [&](int u) -> void {
    vis[u] = 1;
    for (int& v : adj[u])
      if (!vis[v])
        dfs(v);
  };
  f0(i, n) {
    if (!vis[i])
      c++, dfs(i);
  }
  print(mod_pow(2, c));
}
