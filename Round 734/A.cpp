void solve() {
  int n;
  cin >> n;
  int c1 = n / 3;
  int c2 = (n - n / 3) / 2;
  if (c1 + 2 * c2 < n) c1++;
  else if ( c1 + 2 * c2 > n) c1--;
  print(c1, c2);
}
