void solve() {
  int n, k;
  cin >> n >> k;
  vi A(n);
  cin >> A;
  ll ans = -LINF;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i - 1; j >= 0 && j >= i - 1 - 150; j--)
      cmax(ans, (i + 1) * 1LL * (j + 1) - k * (A[i] | A[j]));
  }
  print(ans);
}
