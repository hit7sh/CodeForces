void solve() {
  int n, k, s;
  cin >> n;
  vl A(n), B(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i] >> B[i];
  }
  ll total = accumulate(all(A), 0LL);
  ll ans = 2 * total;
  vi order(n);
  iota(all(order), 0);
  sort(all(order), [&](int a, int b) {
    return B[a] > B[b];
  });
 
  ll cur = total;
  for (int i : order) {
    ll can = max(0LL, min(cur - B[i], A[i]));
    ans -= can;
    cur -= can;
  }
  print(ans);
}
 
