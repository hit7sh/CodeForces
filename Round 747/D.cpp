void solve() {
  int n, m;
  int u, v;
  cin >> n >> m;
  vector<vector<pii>> adj(n + 1);
  f0(i, m) {
    string t;
    cin >> u >> v >> t;
    adj[u].EB(v, t[0] == 'i');
    adj[v].EB(u, t[0] == 'i');
  }
 
  bool bad = 0;
  vi col(n + 1, -1);
  int ans = 0;
  f1(i, n) if (col[i] == -1) {
    vi cnt(2);
    queue<int> q;
    q.push(i);
    col[i] = 1;
 
    while (sz(q)) {
      int u = q.front(); q.pop();
      cnt[col[u]]++;
 
      for (auto& [v, t] : adj[u]) {
        if (col[v] != -1) {
          if (t == 1 && col[u] == col[v]) bad = 1;
          else if (t == 0 && col[u] != col[v]) bad = 1;
          continue;
        }
 
        if (t == 1) col[v] = col[u] ^ 1;
        else col[v] = col[u];
 
        q.push(v);
      }
    }
    ans += max(cnt[0], cnt[1]);
  }
  print(bad ? -1 : ans);
}
 
