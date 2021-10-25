void solve() {
  int n, h;
  cin >> n >> h;
  vi A(n);
  cin >> A;
  sort(rall(A));
  int a = A[0], b = A[1];
  int ans = h / (a + b);
  int rem = h % (a + b);
  h -= ans * (a + b);
  ans *= 2;
  // dbg(h);
  if (h > 0) h -= a, ans++;
  if (h > 0) h -= b, ans++;
  print(ans);
}
 
