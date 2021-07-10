void solve() {
  ll n, ans = 0, p = 1;
  cin >> n;
  for (int i = 2; i < 100000; i++) {
    ll cur = n / p - n / lcm(i, p);
    ans = (ans + cur * i % mod) % mod;
    p = lcm(i, p);
    if (p > n) break;
  }
  print(ans);
} 
