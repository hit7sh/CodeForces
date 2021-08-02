void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 0 && m % 2 == 0) {
    int can = m * n / 2;
    Yes(k % 2 == 0 && k <= can);
  } else {
    if (m & 1) {
      int can = (m - 1) * n / 2;
    Yes(k % 2 == 0 && k <= can);
    } else {
      int can = (n - 1) * m / 2;
      int must = m / 2;
      k -= must;
      Yes(k >= 0 && k % 2 == 0 && k <= can);
    }
  }
}
