void solve() {
  int n, d;
  cin >> n >> d;
  vi A(n);
  cin >> A;
 
  vi vis(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    // print(vis);
    if (!vis[i]) {
      vis[i] = 1;
      vi b;
      b.EB(A[i]);
      int x = (i + d) % n;
      while (!vis[x]) {
        vis[x] = 1;
        b.EB(A[x]);
        x = (x + d) % n;
      }
      vi p;
      f0(j, sz(b)) {
        if (b[j] == 0) {
          p.EB(j);
        }
      }
 
      if (p.empty()) {
        ans = INF;
        continue;
      }
 
      int m = sz(p);
      f0(j, m - 1) {
        cmax(ans, p[j + 1] - p[j] - 1);
      }
      cmax(ans, p[0] + sz(b) - p[m - 1] - 1);
    }
  }
  print(ans == INF ? -1 : ans);
}
 
