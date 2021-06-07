 
void solve() {
 int n;
 string s;
 cin >> s;
 n = sz(s);
 vvi dp(2, vi(n + 1));
 
 for (int i = 0; i < n; i++) {
  if (s[i] != '0')
    dp[1][i + 1] = 1 + dp[0][i];
  if (s[i] != '1')
    dp[0][i + 1] = 1 + dp[1][i];
 }
 
 ll ans = 0;
 for (int i = 1; i <= n; i++) 
  ans += max(dp[1][i], dp[0][i]);
 
  print(ans); 
}
 
