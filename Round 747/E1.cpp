void solve() {
  int n;
  cin >> n;
  vl dp(6, 1);
  while (--n) {
    vl ndp(6);
    f0(i, 6) f0(j, 6) f0(k, 6) if (i != j && i != k && j != (i + 1) % 6 && k != (i + 1) % 6) {
      if (j == k) ndp[i] = (ndp[i] + dp[j] * dp[k] % mod) % mod;
      else ndp[i] = (ndp[i] + dp[j] * dp[k] % mod) % mod;
    }
    dp = ndp;
  }
  ll ans = 0;
  f0(i, 6) ans = (ans + dp[i]) % mod;
  // dbg(dp);
  print(ans);
}
 
