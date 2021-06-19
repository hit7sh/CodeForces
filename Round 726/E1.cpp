void solve() {
  int n, k;
  string og;
  cin >> n >> k >> og;
  string s = og;
  for (int i = n; i < k; i++) {
    s += 'z' + 1;
  }
  for (int i = 0; i < k; i++) {
    if (og < s.substr(i, n)) {
      for (int j = 0; j < n && i + j < k; j++) {
        s[i + j] = og[j];
      }
    }
  }
  for (int i = 0; i < k; i++) {
    cout << s[i];
  }
}
