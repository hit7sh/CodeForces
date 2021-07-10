void solve() {
  int n, a, b;
  bool ok = 0;
  cin >> n >> a >> b;
  for (ll x = 1; x <= n; x *= a) {
    if ((n - x) % b == 0) ok = 1;
    if (a == 1) break;
  }
  Yes(ok);
} 
 
