void solve() {
  int caves;
  cin >> caves;
  vector<vl> A(caves);
  f0(i, caves) {
    int k, x;
    cin >> k;
    while (k--) {
      cin >> x;
      A[i].PB(x);
    }
  }
  vl T;
  for (auto& y : A) {
    ll L = 1, R = 1e16, M;
    while (R - L > 1) {
      M = (L + R) / 2;
      ll P = M;
      bool ok = 1;
      for (ll& x : y) {
        if (P > x) P++;
        else ok = 0;
      }
      if (ok) R = M;
      else L = M;
    }
    T.EB(R);
  }
  // dbg(T);
  vi order(caves);
  iota(all(order), 0);
  sort(all(order), [&](int i, int j) {
    return T[i] < T[j];
  });
  
  ll L = 1, R = 1e16, M;
  while (R - L > 1) {
    M = L + (R - L) / 2;
    bool ok = 1;
 
    ll P = M;
    for (auto& i : order)
      for (auto & x : A[i])
        if (P > x) P++;
        else { ok = 0; break; }
 
    if (ok) R = M;
    else L = M;
  }
  print(R);
}
