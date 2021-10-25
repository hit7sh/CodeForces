void solve() {
  int n, x;
  cin >> n;
  vi cnt(30);
  f0(i, n) {
    cin >> x;
    f0(j, 30) cnt[j] += x >> j & 1;
  }
  f1(i, n) {
    bool ok = 1;
    f0(j, 30) ok &= cnt[j] % i == 0;
    if (ok) cout << i << ' ';
  }
  cout << '\n';
}
 
