void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  ll sm = accumulate(all(A), 0LL);
  if (sm == n) {
    print(0);
  }
  else if (sm <= n) {
    print(1);
  } else
    print(abs(sm - n));
}
 
