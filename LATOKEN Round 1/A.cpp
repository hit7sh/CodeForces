void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  cin >> s;
  string to = "RW";
  bool ok1 = 1, ok2 = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ok1 &= s[i][j] == '.' or s[i][j] == to[(i + j) % 2];
      ok2 &= s[i][j] == '.' or s[i][j] == to[(i + j + 1) % 2];
    }
  }
  if (ok1) {
    Yes(1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << to[(i + j) % 2];
      cout << endl;
    }
  } else if (ok2) {
    Yes(1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << to[(i + j + 1) % 2];
      cout << endl;
    }
  } else {
    cout << "No" << endl;
  }
}
 
