void solve() {
  int n, k;
  cin >> n >> k;
  vvi adj(n);
 
  f0(i, n - 1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].EB(v);
    adj[v].EB(u);
  }
  // if (n == 1) {
  //   print(0);
  //   return;
  // }
  queue<queue<int>> q;
  vi vis(n), nv(n), deg(n);
  f0(i, n) deg[i] = sz(adj[i]);
  queue<int> temp;
  f0(i, n) if (deg[i] <= 1) temp.push(i);
  q.push(temp);
 
  while (k > 0 && sz(q)) {
    --k;
    queue<int> cur, now = q.front();
    q.pop();
    queue<int> qq;
    while (sz(now)) {
      int x = now.front(); now.pop(); qq.push(x);
      vis[x] = 1;
      for (int y : adj[x]) deg[y]--;
    }
  now = qq;
    while (sz(now)) {
      int x = now.front(); now.pop();
      for (int y : adj[x]) if (!vis[y] && !nv[y] && deg[y] <= 1) {
        cur.push(y), nv[y] = 1;
        // cout << y + 1 << ' ';
      }
    }
    if (sz(cur)) q.push(cur);
  } 
  print(count(all(vis), 0));
}
