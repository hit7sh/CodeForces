void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  if (A[0] == 1) {
    cout << n + 1 << ' ';
    f1(i, n) cout << i << " \n"[i == n];
    return;
  }
  if (A[n - 1] == 0) {
    f1(i, n + 1) cout << i << " \n"[i == n + 1];
    return;
  }
  bool found = 0;
  int where = -1;
  for (int i = 1; i < n; i++) {
    if (A[i - 1] == 0 && A[i] == 1) {
      found = 1, where = i;
      break;
    }
  }
  if (!found) {
    print(-1);
    return;
  }
  for (int i = 1; i <= where; i++) {
    cout << i << ' ';
  }
  cout << n + 1 << ' ';
  for (int i = where + 1; i <= n; i++) {
    cout << i << " \n"[i == n];
  }
}
