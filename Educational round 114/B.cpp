void solve() {
  ll a, b, c, m;
  cin >> a >> b >> c >> m;
  ll mx = a + b + c - 3;
  if (m > mx) {
    print("No");
    return;
  }
  vl A = {a, b, c};
  sort(all(A));
  ll mn = A[2] - A[1] - A[0] - 1;
 
  Yes(m >= mn);
}
