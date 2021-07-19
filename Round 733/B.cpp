void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n, string(m, '0'));
  function<bool(int, int)> can = [&](int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
  };
  f0(i, n) f0(j, m) {
    bool put = 1;
    if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
      for (auto [dx, dy] : DD) {
        int x = i + dx, y = j + dy;
        if (can(x, y)) {
          put &= s[x][y] != '1';
        }
      }
    if (put) s[i][j] = '1';
    }
  }
  for (string& x : s) print(x);
}
