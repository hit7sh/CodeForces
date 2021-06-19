void solve() {
  int n, m, x, y;
  cin >> n >> m;
  vvi adj(n + 1);
  vl V(n), T(n);
  cin >> V >> T;
  V.insert(V.begin(), 0);
  T.insert(T.begin(), 0);
  for (int i = 1; i <= n; i++) {
    V[i] -= T[i];
    T[i] = 0;
  }
 
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x].EB(y);
    adj[y].EB(x);
  }
 
  vi vis(n + 1), color(n + 1);
 
  if (checkBipartite(adj, 1, vis, color)) {
    ll sm[2] = {};
    for (int i = 1; i <= n; i++) {
      sm[color[i]] += V[i];
    }
 
    Yes(sm[0] == sm[1]);
  } else {
    Yes(accumulate(all(V), 0LL) & 1 ^ 1);
  }
}
 
