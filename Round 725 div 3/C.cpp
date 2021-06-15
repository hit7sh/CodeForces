void solve() {
  ll n, l, r;
  cin >> n >> l >> r;
  vl A(n);
  cin >> A;
  sort(all(A));
 
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] > r) continue;
    ll frm = max(0LL, l - A[i]);
    ll to = r - A[i];
    ans += UB(all(A), to) - LB(all(A), frm);
    ans -= A[i] >= frm && A[i] <= to;
  }
  print(ans / 2);
}
