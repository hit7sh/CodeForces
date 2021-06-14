void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  A.insert(A.begin(), 0);
  A.EB(0);
 
  ll op = 0;
  for (int i = 1; i <= n; i++) {
    if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
      op += A[i] - max(A[i - 1], A[i + 1]);
      A[i] = max(A[i - 1], A[i + 1]);
    }
  } 
 
  ll len = 0;
  for (int i = 1; i <= n; i++) {
    if (A[i] > A[i - 1])
      len += A[i] - A[i - 1];
    if (A[i] > A[i + 1])
      len += A[i] - A[i + 1];
  }
  print(len + op);
}
 
