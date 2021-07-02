 
void solve() {
  ll n, x, t;
  cin >> n >> x >> t;
  ll div = min(n - 1, t / x);
  if (t == x) print(n - 1);
  else if (x > t) print(0);
  else {
    ll ans = (n - div) * div;
    ans += max(0ll, div * (div - 1) / 2);
    print(ans);
  }
}
 
