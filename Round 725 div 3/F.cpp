void solve() {
  int L, R;
  cin >> L >> R;
  ll ans = 0;
  while (L or R) {
    ans += R;
    ans -= L;
    R /= 10, L /= 10;
  }
  print(ans);
}
