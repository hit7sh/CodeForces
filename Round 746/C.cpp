void solve() {
  int n, k;
  cin >> n >> k;
  vvi adj(n);
  vi A(n);
  cin >> A;
  int X = 0;
  for (int x : A) X ^= x;
 
  f0(i, n - 1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].EB(v);
    adj[v].EB(u);
  }
 
  if (X == 0) {
    Yes(1);return;
  }
 
  if (k == 2) {
    Yes(0); return;
  }
 
  bool ok = 0;
 
  function<int(int, int)> dfs = [&](int u, int p) {
    int cnt = 0;
    for (int v : adj[u]) if (v != p) {
      cnt += dfs(v, u);
      A[u] ^= A[v];
    }
    if (cnt >= 2) ok = 1;
    if (A[u] == 0 && cnt > 0) ok = 1;
 
    cnt += A[u] == X;
    return cnt > 0;
  };
  dfs(0, -1);
  Yes(ok);
}
