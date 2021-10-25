 
void solve() {
  int n;
  cin >> n;
  vi A(n), B(n);
  cin >> A >> B;
  reverse(all(A));
  reverse(all(B));
  vi land(n), go(n);
  f0(i, n) land[i] = i - B[i];
  f0(i, n) if (i + A[i] >= n) go[i] = n; else go[i] = land[i + A[i]];
  queue<int> q;
  vi vis(n), dist(n + 1), par(n + 1);
  vi nxt(n);
  iota(all(nxt), 1);
  q.push(0);
 
  while (sz(q)) {
    int u = q.front(), tu = u;
    u = land[u];
    q.pop();
    vis[u] = 1;
    int now = nxt[u];
 
    while (now <= n && now <= u + A[u]) {
      // dbg(u, now);
      if (now == n) {
        par[n] = tu;
        dist[now] = 1 + dist[u];
        goto done;
      }
      if (!vis[now]) {
       q.push(now), par[now] = tu, dist[now] = 1 + dist[u];
       vis[now] = 1;
      }
      int t = nxt[now];
      nxt[now] = min(n, u + A[u] + 1);
      now = t;
    }
    nxt[u] = min(n, u + A[u] + 1);
    // if (u == 1) dbg(par);
  }
  done:;
  // dbg(par);
  if (dist[n] == 0) print(-1);
  else {
    int now = n;
    vi ans;
    while (now != 0) {
      ans.EB(now);
      now = par[now];
    }
    reverse(all(ans));
    for (int& x : ans) x = n - x;
      print(sz(ans), ans);
  }
}
 
