void solve() {
  int n;
  cin >> n;
  string from, to;
  cin >> to >> from;
  int ans = 0;
  f0(i, n) {
    if (from[i] == '1') {
      if (i - 1 >= 0 && to[i - 1] == '1') {
        ans++;
        to[i - 1] = from[i] = '0';
      } else if (to[i] == '0') {
        ans++;
      } else if (i + 1 < n && to[i + 1] == '1') {
        ans++;
        to[i + 1] = from[i] = '0';
      }
    }
  }
  print(ans);
}
