void solve() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  if (s[n - 1] != '0') {
    ans += s[n - 1] - '0';
  }
  s[n - 1] = '0';
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != '0') ans += s[i] - '0' + 1;
  }
  print(ans);
}
 
