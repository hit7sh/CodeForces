 
void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  dsu D1(n), D2(n);
  int u, v;
  f0(i, m1) {
    cin >> u >> v;
    D1.unite(u, v);
  }
  f0(i, m2) {
    cin >> u >> v;
    D2.unite(u, v);
  }
  int need = min(D1.components, D2.components) - 1;
  vector<pii> ans;
  vi L(n + 1), R(n + 1);
  for (int i = 2; i <= n; i++) {
    if (D1.get(1) != D1.get(i) && D2.get(1) != D2.get(i)) {
      ans.EB(1, i);
      D1.unite(1, i);
      D2.unite(1, i);
    }
  }
  int a = 0, b = 0;
  for (int i = 2; i <= n; i++) {
    if (D1.get(1) != D1.get(i)) {
      L[++a] = i;
      D1.unite(1, i);
    }
    if (D2.get(1) != D2.get(i)) {
      R[++b] = i;
      D2.unite(1, i);
    }
  }
 
  for (int i = 1; i <= min(a, b); i++) {
    ans.EB(L[i], R[i]);
  }
 
  assert(sz(ans) == need);
  print(sz(ans));
  for (auto& x : ans)
    print(x);
}
