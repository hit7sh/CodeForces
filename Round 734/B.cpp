void solve() {
  string s;
  cin >> s;
  vi cnt(26);
  for (char x : s) cnt[x - 'a']++;
  int ans = 0, c1 = 0;
  for (int& x : cnt) {
    c1 += x == 1;
    if (x > 1) ans++;
  }
  ans += c1 / 2;
  print(ans);
}
