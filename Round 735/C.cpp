void solve() {
  int n, m;
  cin >> n >> m;
  if (m < n) {
    print(0);
  } else {
    int ans = 0; ++m;
    for (int i = 30; i >= 0 && n < m; i--) {
      if ((n & (1 << i)) == (m & (1 << i))) {
        // if same put 0
        continue;
      }
      if (m & (1 << i)) ans |= 1 << i, n |= 1 << i;
    }
    print(ans);
  }
}
