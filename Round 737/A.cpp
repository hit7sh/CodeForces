void solve() {
  int n;
  cin >> n;
  vl A(n);
  cin >> A;
  sort(all(A));
  ll sm = accumulate(all(A) - 1, 0LL);
  double ans = (double) sm / (n - 1) + A.back();
  print(ans);
}
