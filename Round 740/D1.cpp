void solve() {
  int n;
  cin >> n >> MOD;
  vector<mi> dp(n + 1);
  // dp[n] = number of ways to get from n to 1
  // dp[n] = sum(dp[1]...dp[n - 1]) + ...
  mi sm = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = sm;
    for (int j = 1; j * j <= i; j++) {
      dp[i] += dp[j] * (i / j - i / (j + 1));
      if (j != i / j && j > 1) {
        dp[i] += dp[i / j];
      }
    }
    sm += dp[i];
  }
  print(dp[n]);
}
 
