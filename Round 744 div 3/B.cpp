void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  vvi op;
  for (int i = 0; i < n - 1; i++) {
    auto it = min_element(i + all(A));
    int R = it - A.begin(), d = R - i;
    // dbg(R);
    if (i == R) continue;
    it++;
    rotate(i + A.begin(), i + A.begin() + d, it);
    op.push_back({i + 1, R + 1, d});
  }
  assert(is_sorted(all(A)));
  print(sz(op));
  for (auto& x : op) print(x);
}
 
