void solve() {
  int n;
  cin >> n >> MOD;
  vector<mi> dp(n+1, 0);
  vector<mi> pref(n+1, 0);
  dp[1] = 1;
  mi sm = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] += pref[i - 1];
    dp[i] += sm + pref[i];
    for (int j = i + i, it = 2; j <= n; j += i, it++) {
      int L = j, R = j + it;
      pref[j] += dp[i];
      if (R <= n) pref[R] -= dp[i];
    }
    sm += dp[i];
  }
  print(dp[n]);
}
