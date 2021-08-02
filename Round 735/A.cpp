void solve() {
  int n, m;
  cin >> n;
  vi A(n);
  cin >> A;
  ll ans = 0;
  f1(i, n - 1) {
    cmax(ans, A[i] * 1LL * A[i - 1]);
  }
  print(ans);
}
