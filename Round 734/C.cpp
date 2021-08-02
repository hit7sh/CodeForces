void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  int ans = 0;
  for (int p = 0; p < 5; p++) {
    vi cnt(n);
    f0(i, n) for(char& x : s[i]) {
      if (x - 'a' == p) cnt[i]++;
      else cnt[i]--;
    }
    sort(rall(cnt));
    for (int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
    f0(i, n) {
      if (cnt[i] > 0)
        cmax(ans, i + 1);
    }
  }
  print(ans);
}
