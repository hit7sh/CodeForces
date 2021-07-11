void solve() {
  ll n, k;
  cin >> n >> k;
  vl A(k), T(n + 1, INF), t(k);
  cin >> A >> t;
  vector<pair<ll, ll>> st;
  for (ll i = 0; i < k; i++) {
    T[A[i]] = t[i];
    st.emplace_back(t[i], A[i]);
  }
  sort(all(st));
 
  for (auto& [temp, idx] : st) {
    ll L = 1, R = 1;
    while (idx - L > 0 && T[idx - L] > temp + L)
      T[idx - L] = temp + L, L++;
    while (idx + R <= n && T[idx + R] > temp + R)
      T[idx + R] = temp + R, R++;
    // dbg(temp, idx);
  }
 
  for (ll i = 1; i <= n; i++) 
    cout << T[i] << " \n"[i == n];
}
