void solve() {
  int n;
  cin >> n;
  vvi A(n);
  vi c(n);
  f0(i, n) {
    cin >> c[i];
    A[i] = vi(c[i]);
    cin >> A[i];
  }
  int m;
  cin >> m;
  vvi B(m, vi(n));
  cin >> B;
  sort(all(B));
  for (auto& y : B) for(int& x : y) --x;
  set<pair<int, vi>> st;
  {
  int sm = 0;
  vi ans(n);
  f0(i, n) sm += A[i].back(), ans[i] = c[i] - 1;
  st.emplace(sm, ans);
  }
  while (sz(st)) {
    auto it = st.end(); --it;
    int sum = it->F;
    vi ans = it->S;
    st.erase(it);
    if (!binary_search(all(B), ans)) {
      for (int& x : ans) cout << x + 1 << ' ';
        return;
    }
 
    for (int i = n - 1; i >= 0; i--) {
      if (ans[i] > 0) {
        int nsm = sum - A[i][ans[i]] + A[i][ans[i] - 1];
        ans[i] -= 1;
        st.emplace(nsm, ans);
        ans[i] += 1;
      }
      if (ans[i] < c[i] - 1) break; // if found new ans
    }
  } 
}
