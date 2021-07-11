void solve() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  if (a > c or b > d) swap(a, c), swap(d, b);
  int ans = abs(c - a) + abs(d - b);
  if ((a == c && c == e) && (f > b && f < d)) ans += 2;
  if ((b == d && d == f) && (e > a && e < c)) ans += 2;
  print(ans);
}
