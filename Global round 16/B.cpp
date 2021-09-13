void solve() {
  string s;
  cin >> s;
  string t = s;
  t.erase(unique(all(t)), t.end());
  int cur = 0;
  for (char x : t) cur += x == '0';
  int ans = 0;
  bool c0 = 0, c1 = 0;
  for (char x : s) c0 |= x == '0', c1 |= x == '1';
  if (c0 && c1) ans = 2;
  else if (!c0) ans = 0;
  else if (!c1) ans = 1;
  print(min(cur, ans));
}
 
