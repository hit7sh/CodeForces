 
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int m = -1;
  f0(i, n) {
    if (s[i] != '?') {
      m = i; break;
    }
  }
  string t = "RB";
  if (m == -1) {
    f0(i, n) cout << t[i & 1];
    cout << endl;
    return;
  }
  for (int i = m - 1; i >= 0; i--) {
    if (s[i] == '?')
      s[i] = s[i + 1] ^ t[0] ^ t[1];
  }
  for (int i = m + 1; i < n; i++) {
    if (s[i] == '?')
      s[i] = s[i - 1] ^ t[0] ^ t[1];
  }
  print(s);
}
