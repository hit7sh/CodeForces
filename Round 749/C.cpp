void solve() {
  int n, m;
  cin >> n >> m;
  dsu D(n * m);
  vector<string> s(n);
  cin >> s;
  vi P(m + 1);
  for (int i = 0; i + 1 < n; i++) {
    for (int j = 0; j + 1 < m; j++) {
      if (s[i + 1][j] != '.' && s[i][j + 1] != '.') P[j + 1] = 1;
    }
  }
  for (int j = 1; j <= m; j++) P[j] += P[j - 1];
 
  int Q, L, R;
  cin >> Q;
  dbg(P);
  while (Q--) {
    cin >> L >> R;
    Yes(P[L - 1] == P[R - 1]);
  }
}
