void solve() {
  int n, m, k;
  cin >> k >> n >> m;
 
  vi A(n), B(m), ans;
  cin >> A >> B;
  int i, j;
  for (i = 0, j = 0; i < n or j < m; ) {
    int c = 0;
    while (i < n && A[i] <= k) {
      if (A[i] == 0) k++;
      ans.EB(A[i]);
      i++;
      c++;
    }
 
    while (j < m && B[j] <= k) {
      if (B[j] == 0) k++;
      ans.EB(B[j]);
      j++;
      c++;
    }
    if (!c) {
      print(-1); return;
    }
  }
 
  print(ans);
}
