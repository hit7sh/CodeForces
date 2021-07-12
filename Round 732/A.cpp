void solve() {
  int n;
  cin >> n;
  vi A(n), B(n);
  cin >> A >> B;
  int i, j;
  vector<pii> op;
  if (accumulate(all(A), 0) != accumulate(all(B), 0)) {
    print(-1);
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      while (A[i] > B[i] && A[j] < B[j]) {
        op.EB(i + 1, j + 1);
        A[i]--, A[j]++;
      }
    }
  }
  print(sz(op));
  for (auto x : op)
    print(x);
  // dbg(A, B);
}
