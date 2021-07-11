void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  n *= 2;
  vector<vector<int>> ST(20, vi(n));
  for (int i = 0; i < n / 2; i++) A.EB(A[i]);
  ST[0] = A;
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j <= n - (1 << i); j++) {
      ST[i][j] = gcd(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
    }
  }
  function<int(int, int)> qry = [&](int x, int y) {
    int dif = y - x + 1;
    int msb = 31 - __builtin_clz(dif);
    return gcd(ST[msb][x], ST[msb][y - (1 << msb) + 1]);
  };
  // dbg(qry(n, n + 1));
 
  int L = -1, R = n / 2 + 1;
  while (R - L != 1) {
    int M = (L + R) / 2;
    if (M == -1) {
      R = 0; break;
    }
    // check at step M;
    set<int> st;
    for (int i = 0; i < n / 2; i++)
      st.insert(qry(i, i + M));
    if (sz(st) == 1)
      R = M;
    else L = M;
  }
  cout << R << endl;
}
