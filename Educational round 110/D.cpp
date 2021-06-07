void solve() {
  int k;
  cin >> k;
  int n = (1 << k);
  vi dp(n);
  string s; cin >> s; s += '#'; reverse(all(s));
  function<void(int)> update = [&](int x) {
    if (x >= n) return;
    if (x >= (1 << (k - 1))) {
      dp[x] = 1 + (s[x] == '?');
      return;
    }
 
    if (s[x] == '?')
      dp[x] = dp[x*2] + dp[x * 2 + 1];
    else if (s[x] == '0')
      dp[x] = dp[x * 2 + 1];
    else if (s[x] == '1')
      dp[x] = dp[x * 2];
  };
  for (int i = (1 << k) - 1; i > 0; i--) {
    update(i);
  }
  int q; cin >> q;
  while (q--) {
    int p; char c;
    cin >> p >> c;
    p = n - p;
    s[p] = c;
    while (p > 0) {
      update(p); p /= 2;
    }
    print(dp[1]);
  }
}
 
