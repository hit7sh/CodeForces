void solve() {
  int n, k, must = 1;
  cin >> n >> k;
  vi A(n);
  cin >> A;
  vi order(n);
  iota(all(order), 0);
  sort(all(order), [&](int i, int j) {
    return A[i] < A[j];
  });
  f0(i, n - 1) {
    must += order[i] + 1 != order[i + 1];
  }
  Yes(k >= must);
}
