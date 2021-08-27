void solve() {
  ll l, r;
  cin >> l >> r;
  if (l == r) print(0);
  // else if (r - l == 1) print(1);
  else {
    vl pos;
    pos.EB(l);
    pos.EB(r);
    if (r / 2 >= l)
      pos.EB(r / 2);
    if (r / 2 - 1 >= l)
      pos.EB(r / 2 - 1);
    if (r / 2 + 1 >= l && r / 2 + 1 <= r)
      pos.EB(r / 2 + 1);
    int ans = 0;
    dbg(pos);
    for (ll x : pos)
      cmax(ans, r % x);
    print(ans);
  }
}
