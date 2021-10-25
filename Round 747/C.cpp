void solve() {
  int n;
  char c;
  string s;
  cin >> n >> c >> s;
 
  if (sz(set<char>(all(s))) == 1 && s[0] == c) {
    print(0);
    return;
  }
  vi ans;
  s.insert(s.begin(), '0');
 
  int mx = -1, who = -1, tot = count(all(s), c);
  tot = n - tot;
  f1(i, n) {
    int cc = 0;
    for (int j = i; j <= n; j += i) {
      cc += s[j] != c;
    }
    int can = tot - cc;
    if (cmax(mx, can)) who = i;
  }
  // dbg(who);
  ans.EB(who);
  f1(i, n) if (i % who != 0 && s[i] != c) s[i] = c, tot--;
  dbg(s, tot);
  if (tot > 0) {
    mx = -1, who = -1;
    f1(i, n) {
      int cc = 0;
      for (int j = i; j <= n; j += i) {
        cc += s[j] != c;
      }
      int can = tot - cc;
      if (cmax(mx, can)) who = i;
    }
    f1(i, n) if (i % who != 0 && s[i] != c) s[i] = c, tot--;
    ans.EB(who);
  }
  assert(tot == 0);
  print(sz(ans), ans);
}
