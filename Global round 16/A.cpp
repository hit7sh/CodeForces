void solve() {
  ll n, s;
  cin >> n >> s;
  if (n == 1) {
    print(s); return;
  }
 
  ll left = (n + 1) / 2 - 1;
  ll right = n - ((n + 1) / 2 - 1);
  // dbg(left, right, n);
  // s -= left;
  print((s) / right);
}
