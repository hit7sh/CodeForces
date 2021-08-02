 
void solve() {
  int n, k;
  cin >> n >> k;
  vi A(n);
  cin >> A;
  vvi pos(n);
  f0(i, n) {
    A[i] -= 1;
    pos[A[i]].EB(i);
  }
  vi ans(n, -1);
  int cnt = 0;
  for (auto& x : pos) {
    if (sz(x) >= k) {
      int v = 0;
      for (int i = 0; i < k; i++)
        ans[x[i]] = v++;
    } else cnt += sz(x);
  }
  int to = cnt / k;
  // dbg(cnt);
  int g = 0;
  for (auto& x : pos) {
    if (to > 0 && sz(x) < k) {
      for (int& y : x) {
        ans[y] = g;
        // print(y, g, to);
        if (g == k - 1) to -= 1;
        // dbg(y, g, to);
        if (to == 0) break;
        g = (g + 1) % k;
      }
    }
  }
 
  for (int& x : ans) x++;
  print(ans);
  // mii f;6
}
 
