void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  compress(A);
  fenwick<ll> ft(n + 2);
  deque<int> dq;
  dq.push_back(A[0]);
  ft.modify(A[0], +1);
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    int o1 = ft.get(A[i] - 1); // L
    int o2 = ft.get(n) - ft.get(A[i]); // R
    if (o1 < o2) ans += o1;
    else ans += o2;
 
    ft.modify(A[i], +1);  
  }
  print(ans);
}
