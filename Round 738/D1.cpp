void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  dsu D1(n), D2(n);
  int u, v;
  f0(i, m1) {
    cin >> u >> v;
    D1.unite(u, v);
  }
  f0(i, m2) {
    cin >> u >> v;
    D2.unite(u, v);
  }
  vector<pii> ans;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (D1.get(i) != D1.get(j) && D2.get(i) != D2.get(j)) {
        ans.EB(i, j);
        D1.unite(i, j);
        D2.unite(i, j);
      }
    }
  }
  print(sz(ans), ans);
}
