void solve() {
  int n, k;
  cin >> n >> k;
  vi A(n);
  cin >> A; 
  int dp[n][n];
  memset(dp, 0xc0, sizeof(dp));
  if (n == 1) {
    print(A[0] == 1 ? 0 : -1);
    return;
  }
  dp[0][0] = dp[0][1] = 0;
  if (A[0] == 1) dp[0][0] = 1;
  for(int i=1; i < n; i++)
        for(int j=0; j < n; j++)
            if(dp[i-1][j] >= 0)
            {
                int add = 0;
                if(A[i]+j == i+1)
                    add = 1;
                dp[i][j] = max(dp[i][j], dp[i-1][j]+add);
                if(j+1 < n)
                    dp[i][j+1] = max(dp[i][j+1], dp[i-1][j]);
            }
  int ans = -1;
  for (int j = 0; j < n; j++) {
    if (dp[n - 1][j] >= k) {
      ans = j;
      break;
    }
  }
  print(ans);
}
