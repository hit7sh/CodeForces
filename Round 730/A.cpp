void solve() {
  ll a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  if (a == b) {
    print(0, 0);
  } else {
    ll dif = b - a;
    print(dif, min(b % dif, dif - (b % dif)));
  }
} 
