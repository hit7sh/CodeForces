vi chk(int a, int b, int c) {
  if (a + b != 0) return {c, c, -(a + b)};
  else if (b + c != 0) return {-(b + c), a, a};
  else return {b, -(a + c), b};
}
 
void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  if (~n & 1) {
    f0(i, n) {
      cout << -A[i + 1] << ' ' << A[i] << ' ';
      i++;
    }
    cout << '\n';
    return;
  }
 
  int a = A[n - 3], b = A[n - 2], c = A[n - 1];
  n -= 3;
 
  f0(i, n) {
    cout << -A[i + 1] << ' ' << A[i] << ' ';
    i++;
  }
  vi t = chk(a, b, c);
  print(t);
}
