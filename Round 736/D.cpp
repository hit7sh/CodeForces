void solve() {
  int n;
  cin >> n;
  vl A(n);
  cin >> A;
  if (n == 1) {
    print(n);
    return;
  }
  vl dif(n);
  f1(i, n - 1) {
    dif[i] = abs(A[i] - A[i - 1]);
  }
 
  vector<vector<ll>> ST(20, vl(n));
  ST[0] = dif;
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j <= n - (1 << i); j++) {
      ST[i][j] = gcd(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
    }
  }
  function<ll(int, int)> qry = [&](int x, int y) {
    int df = y - x + 1;
    int msb = 31 - __builtin_clz(df);
    return gcd(ST[msb][x], ST[msb][y - (1 << msb) + 1]);
  };
  int ans = 1;
  f0(i, n - 1) {
    int L = i, R = n, M;
    while (R - L > 1) {
      M = (L + R) / 2;
      if (qry(i + 1, M) > 1)
        L = M;
      else R = M;
    }
    cmax(ans, L - i + 1);
    // if (cmax(ans, L - i + 1)) dbg(i, L, T.query(i, L).sm);
  }
  print(ans);
}
