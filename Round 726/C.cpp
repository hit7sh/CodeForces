 
void solve() {
  int n;
  cin >> n;
  vl A(n);
  cin >> A;
  sort(all(A));
  
  ll mnd = LINF;
 
  ll a, b;
  for (int i = 1; i < n; i++) {
    if (A[i] - A[i - 1] < mnd) {
      mnd = A[i] - A[i - 1];
      a = A[i - 1], b = A[i];
    }
  }
 
  A.erase(LB(all(A), a));
  A.erase(LB(all(A), b));
  n -= 2;
  int from = UB(all(A), b) - A.begin() - 1;
  vi ans; ans.EB(b);
 
  for (int i = from; i >= 0; i--)
    ans.EB(A[i]);
  for (int i = n - 1; i > from; i--)
    ans.EB(A[i]);
  ans.EB(a);
  reverse(all(ans));
  print(ans);
}
