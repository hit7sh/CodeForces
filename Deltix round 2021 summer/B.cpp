void solve() {
  ll ans = LINF;
  int n;
  cin >> n; 
  vi A(n);
  for (int& x : A) cin >> x, x &= 1;
  vi pos;
  f0(i, n) if (A[i]) pos.EB(i);
  f0(k, 2) {
    vi to;
    ll now = 0;
    for (int i = k; i < n; i += 2) {
      to.EB(i);
    }
    if (sz(to) == sz(pos)) {
      f0(i, sz(to)) now += abs(to[i] - pos[i]);
      cmin(ans, now);
    }
  }
  print(ans == LINF ? -1 : ans);
}
