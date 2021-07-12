void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  vi E, O;
  for (int i = 0; i < n; i++) {
    if (i & 1)
      O.EB(A[i]);
    else E.EB(A[i]);
  }
  sort(rall(E));
  sort(rall(O));
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      A[i] = O.back();
      O.pop_back();
    } else {
      A[i] = E.back();
      E.pop_back();
    }
  }
  assert(E.empty() && O.empty());
  Yes(is_sorted(all(A)));
}
