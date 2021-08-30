void solve() {
  int n, q, L, R;
  cin >> n >> q;
  vi A(n), B(n);
  cin >> A >> B;
 
  vl dif(n + 1);
  f0(i, n) dif[i + 1] = dif[i] + B[i] - A[i];
  SparseTable<ll> mn(dif, [](ll i, ll j) { return min(i, j); });
  SparseTable<ll> mx(dif, [](ll i, ll j) { return max(i, j); });
 
  while (q--) {
    cin >> L >> R;
    
    if (dif[R] - dif[L - 1] != 0 or mn.get(L, R) - dif[L - 1] < 0) {
      print(-1);
      continue;
    }
    print(mx.get(L, R) - dif[L - 1]);
    // answer is the maximum prefix sum of that dif[L ... R];
  }
}
