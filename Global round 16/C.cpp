void solve() {
  int n;
  cin >> n;
  vector<string> s(2);
  cin >> s;
  int ans = 0;
 
  auto get = [](set<char>& sst) {
    int r = 0;
    for (char x : sst) if (x - '0' != r) return r; else r++;
    return r;
  };
  s[0] = " " + s[0];
  s[1] = " " + s[1];
  vi dp(n + 1);
  for (int i = 1; i <= n; i++) {
    set<char> t;
    t.insert(s[0][i]); t.insert(s[1][i]);
    dp[i] = dp[i - 1] + get(t);
    t.insert(s[0][i - 1]); t.insert(s[1][i - 1]);
    if (i - 2 >= 0) cmax(dp[i], dp[i - 2] + get(t));
  }
  print(dp[n]);
}
