void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> s(n);
  cin >> s;
  k++;
 
  vvi vis(n, vi(m));
 
  f0(i, n) {
    f0(j, m) if (s[i][j] == '*') {
      int cnt = 0;
      for (int u = i, v = 0; j - v >= 0 && j + v < m && u >= 0 && s[u][j + v] == s[u][j - v] && s[u][j + v] == '*'; u--, v++) {
        cnt++;
      }
      nn:
      if (cnt >= k) {
        for (int u = i, v = 0; cnt > 0 && j - v >= 0 && j + v < m && u >= 0 && s[u][j + v] == s[u][j - v] && s[u][j + v] == '*'; u--, v++) {
        vis[u][j - v] = vis[u][j + v] = 1;
        cnt--;
      }
        bb:;
      }
    }
  }
  bool can = 1;
  f0(i, n) {
    // print(vis[i]);
    f0(j, m) {
      if (s[i][j] == '*') can &= vis[i][j];
      // else can &= !vis[i][j];
    }
  }
  Yes(can);
}
 
