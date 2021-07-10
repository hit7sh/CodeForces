void solve() {
  int n;
  cin >> n;
  char c;
  vi A(n);
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c == '+') cin >> A[i];
    else A[i] = -1;
  } 
 
  mi ans = 0;
  for (int x = 0; x < n; x++) {
    if (A[x] == -1) continue;
    vector<vector<mi>> dp(n + 1, vector<mi>(n + 1));
    dp[0][0] = 1; // don't take anything but A[x]
 
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < n; k++) {
        dp[i + 1][k] += dp[i][k]; // don't take anything but A[x]
        if (i == x) continue;
 
        if (A[i] != -1) {
          bool less = (A[i] < A[x] or (A[i] == A[x] && i < x));
          dp[i + 1][k + less] += dp[i][k];
        } else {
          if (k > 0) dp[i + 1][k - 1] += dp[i][k];
          else if (i < x) dp[i + 1][k] += dp[i][k];
        }
      }
    }
 
    for (int i = 0; i < n; i++) 
      ans += dp[n][i] * A[x];
  }
  print(ans);
} 
