void solve() {
  int k;
  cin >> k;
  ll a, b;
  for (ll x = 1, i = 1; x <= 1e10; i++, x += 2 * i - 1) {
    if (k <= x) {
      ll from = x - 2 * i + 1 + 1, to = x;
      // dbg(from);
      if (k - from <= (x - from + 1) / 2) a = i, b = k - from + 1;
      else b = i, a = x - k + 1;
      break;
    }
  }
  swap(a, b);
  print(a, b);
}
 
