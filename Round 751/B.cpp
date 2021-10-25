void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  vvi dp(n + 1, vi(n));
  dp[0] = A;
  f1(j, n) {
    vi cnt(n + 1);
    f0(i, n) cnt[A[i]]++;
    f0(i, n) dp[j][i] = cnt[A[i]];
    f0(i, n) A[i] = dp[j][i];
  }
 
  // f0(i, 5) print(dp[i]);
  int Q, x, k;
  cin >> Q;
  while (Q--) {
    cin >> x >> k;
    --x;
    k = min(n, k);
    print(dp[k][x]);
  }
}
