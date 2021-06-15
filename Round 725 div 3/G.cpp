void solve() {
  ll x, y, a, b, L = 0, R = 1e9 + 1, M;
 
  cin >> x >> y >> a >> b;
 
  if (a > b) swap(a, b);
 
  while (R - L != 1) {
    M = (L + R) / 2;
 
    ll X = x, Y = y;
    X -= M * a;
    Y -= M * a;
 
    bool ok = (X >= 0 && Y >= 0);
 
    if (b > a) {
      X /= b - a;
      Y /= b - a;
      ok &= (X + Y >= M);
    }
 
    if (ok) L = M;
    else R = M;
  }
  print(L);
 
}
