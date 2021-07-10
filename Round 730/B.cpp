void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  ll sm = accumulate(all(A), 0LL);
  if (sm == 0) {
    print(0);
    return;
  }
  ll t = sm / n;
  A = vi(n, t);
  for (int i = 0; i < sm % n; i++)
    A[i]++;
  ll ans = 0, P = n - 1, N = 0;
  for (int i = 0; i < n; i++) {
    ans += P * A[i] - N * A[i];
    P--, N++;
  }
  print(ans);
} 
 
