void solve() {
  int n, k;
  cin >> n >> k;
  vi A(n);
  cin >> A;
  if (is_sorted(all(A))) {
    Yes(1);
    return;
  }
  if (k >= n) {
    Yes(0);
    return;
  }
  int x = n - k;
  bool ok = 1;
  int i, j;
  for (i = 0; i < x; i++);
  for (j = n - 1; x > 0; j--) x--;
  dbg(i, j);
 
  vi B = A;
  sort(all(B));
  for (x = i; x <= j; x++) ok &= A[x] == B[x];
  Yes(ok);
}
