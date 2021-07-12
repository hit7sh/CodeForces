void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int c0 = 0, c1 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') c0++;
    else if (s[i] == '1' && i + 1 < n && s[i + 1] == '1') c1++, i++;
  }
  cout << (fact[c0 + c1] / fact[c0] / fact[c1]) << endl;
}
