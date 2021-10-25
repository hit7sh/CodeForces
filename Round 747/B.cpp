void solve() {
  int n, k;
  cin >> n >> k;
 
  ll ans = 0, pw = 1;
 
  while (k > 0) {
    if (k % 2) ans += pw;
    ans %= mod;
    pw = pw * n % mod;
    k >>= 1;
  }
  print(ans);
}
