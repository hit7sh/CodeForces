void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = " " + s;
  vi val(26);
  vvi pref(n + 1, vi(26));
  int c = 0;
  for (int i = 1; i <= n; i++) {
    if (!val[s[i] - 'a'])
      val[s[i] - 'a'] = ++c;
 
    pref[i][s[i] - 'a'] = 1;
    for (int j = 0; j < 26; j++)
      pref[i][j] += pref[i - 1][j];
  }
 
  while (q--) {
    int l, r;
    cin >> l >> r;
    ll ans = 0;
    for (int i = 0; i < 26; i++) {
      ans += (i + 1) * 1LL * (pref[r][i] - pref[l - 1][i]);
    }
    print(ans);
  }
 
}
 
