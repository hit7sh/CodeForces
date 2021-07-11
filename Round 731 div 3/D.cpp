void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  vi ans;
  ans.EB(0);
 
  for (int i = 1; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < 30; j++) {
      if ((A[i - 1] & (1 << j)) and !(A[i] & (1 << j)))
        cur += 1 << j;
    }
    A[i] += cur;
    ans.EB(cur);
  }
  print(ans);
}
