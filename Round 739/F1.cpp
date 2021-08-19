vi pre;
void init() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      f1(x, 9)
      for (int mask = 0; mask < 1 << x; mask++) {
        int now = 0;
        for (int bit = 0; bit < x; bit++) {
          if (mask & (1 << bit))
            now = now * 10 + i;
          else
            now = now * 10 + j; 
        }
        // if (i == 1 && j == 2) print(now);
        pre.EB(now);
      }
    }
  }
  sort(all(pre));
  // dbg(pre);
}
 
void solve() {
  int n, k;
  cin >> n >> k;
  int len = int(log10(n) + 1);
  if (k == 1) {
    int ans = 1111111111;
    if (len == 10) { print(ans); return; }
    f0(i, 10) {
      int to = stoi(string(len, char(i ^ 48)));
      if (to >= n) cmin(ans, to);
    }
    print(ans);
  } else {
    int ans = 1e9;
    // dbg(n, len);
    if (LB(all(pre), n) != pre.end())
    cmin(ans, *LB(all(pre), n));
    print(ans);
  }
}
