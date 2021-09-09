void solve() {
  int n, m, k;
  cin >> n >> m >> k;
 
  vi V(n), H(m);
  cin >> V >> H;
  V.EB(0); V.EB(1000000);
  H.EB(0); H.EB(1000000);
  sort(all(V)); sort(all(H));
  vi X, Y;
  vector<pii> P;
  map<int, vi> xx, yy;
 
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    bool inv = binary_search(all(V), x);
    bool inh = binary_search(all(H), y);
    if (inv && inh) continue;
    else X.EB(x), Y.EB(y), xx[x].EB(y), yy[y].EB(x), P.EB(x, y);
  }
  for (auto& [p, q] : xx) sort(all(q));
  for (auto& [p, q] : yy) sort(all(q));
 
  sort(all(X)); sort(all(Y));
  ll ans = 0;
  for (auto& [x, y] : P) {
    bool inh = binary_search(all(H), y);
    int cur = 0;
    if (inh) {
      auto left = lower_bound(all(V), x);
      if (left != V.begin()) {
        left--;
        ans += UB(all(X), *left) - X.begin();
        cur += UB(all(X), *left) - X.begin();
      }
      auto right = lower_bound(all(V), x);
      if (right != V.end()) {
        ans += sz(X) - (LB(all(X), *right) - X.begin());
        cur += sz(X) - (LB(all(X), *right) - X.begin());
      }
      int from = x, to = x;
 
      left = LB(all(V), x);
      if (left != V.begin())
        left--, from = *left;
      if (right != V.end())
        to = *right;
 
      ans += int(UB(all(yy[y]), to) - LB(all(yy[y]), from));
      cur += int(UB(all(yy[y]), to) - LB(all(yy[y]), from));
      ans -= 1;cur -= 1;
      // if (x == 4 && y == 4) dbg(from , to);
    } else {
      auto left = LB(all(H), y);
      if (left != H.begin()) {
        left--;
        ans += UB(all(Y), *left) - Y.begin();
        cur += UB(all(Y), *left) - Y.begin();
      }
 
      auto right = LB(all(H), y);
      if (right != H.end()) {
        ans += sz(Y) - (LB(all(Y), *right) - Y.begin());
        cur += sz(Y) - (LB(all(Y), *right) - Y.begin());
      }
 
      int from = y, to = y;
 
      left = LB(all(H), y);
      if (left != H.begin())
        left--, from = *left;
      if (right != H.end())
        to = *right;
      ans += int(UB(all(xx[x]), to) - LB(all(xx[x]), from));
      cur += int(UB(all(xx[x]), to) - LB(all(xx[x]), from));
      ans -= 1, cur -= 1;
      // if (x == 0 && y == 263093) dbg(int(UB(all(xx[x]), to) - xx[x].begin()));
    }
    // dbg(x, y, cur);
  }
  print(abs(sz(X) * 1LL * (sz(X) - 1) / 2 - ans / 2));
}
