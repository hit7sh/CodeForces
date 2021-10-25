void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  vector<pii> ans;
  priority_queue<pii> pq;
  f0(i, n) {
    if (A[i] > 0) pq.push({A[i], i});
  }
  while (sz(pq) > 1) {
    auto a = pq.top();
    pq.pop();
    auto b = pq.top();
    pq.pop();
    ans.EB(a.S + 1, b.S + 1);
    if (a.F > 1) a.F--, pq.push(a);
    if (b.F > 1) b.F--, pq.push(b);
  }
  print(sz(ans));
  for (auto& x : ans) print(x);
}
 
