void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<string> ans(n, string(n, '.'));
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      ans[i] = string(n, '=');
      for (int j = 0; j < n; j++) {
        ans[j][i] = '=';
      }
    }
  }
 
  f0(i, n) ans[i][i] = 'X';
 
  f0(i, n) {
    if (s[i] == '2') {
      bool found = 0;
      f0(j, n) if (i ^ j) {
        if (ans[i][j] == '.') { ans[i][j] = '+', ans[j][i] = '-', found = 1; break; }
      }
      if (!found) {
        print("NO");
        return;
      }
    }
  }
  print("YES");
  f0(i, n) f0(j, n) if (ans[i][j] == '.') ans[i][j] = '+', ans[j][i] = '-';
  for (string x : ans) print(x);
 
}
