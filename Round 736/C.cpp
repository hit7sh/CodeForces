void solve() {
  int n, m;
  cin >> n >> m;
  vi deg(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    deg[min(u, v)]++;
  }
  int q, ans = count(1 + all(deg), 0);
  cin >> q;
  while (q--) {
    int t, u, v;
    cin >> t;
    if (t == 1) {
      cin >> u >> v;
      deg[min(u, v)]++;
      if (deg[min(u, v)] == 1)
        ans--;
    } else if (t == 2) {
      cin >> u >> v;
      deg[min(u, v)]--;
      if (deg[min(u, v)] == 0)
        ans++;
    } else {
      print(ans);
    }
  }
}
