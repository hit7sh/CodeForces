void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b) swap(a, b);
  int n2 = b - a;
  if (((a >= 1 && a <= n2 && b > n2 && b <= 2 * n2) or (b >= 1 && b <= n2 && a > n2&& a <= 2 * n2)) && (1 <= c && c <= 2 * n2)) {
    --c;
    print((c + n2) % (2 * n2) + 1);
    return;
  }
  print(-1);
}
