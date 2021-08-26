void solve() {
  int a, b;
  cin >> a >> b;
  if (a < b) swap(a, b);
  int n = a + b;
 
  vi ans;
  if (n % 2 == 0) {
    int op = n / 2, mn, mx;
    if (a >= op) a -= op;
    mn = a;
    a = n - b;
    if (a >= op) mx = op;
    mx += b;
    a = n - b;
    for (int i = mn; i <= mx; i += 2) {
      ans.EB(i);
    }
  } else {
    int op1 = (n + 1) / 2, mx = b + min(op1, a), mn;
    if (a >= op1) a -= op1;
    mn = a;
    for (int i = mn; i <= mx; i++) {
      ans.EB(i);
    }
  }
  print(sz(ans), ans);
}
