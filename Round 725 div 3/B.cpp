void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  ll sm = accumulate(all(A), 0LL);
  if (sm % n) {
    print(-1);
    return;
  }
  ll avg = sm / n;
  int ans = 0;
  for (int& x : A)
    ans += x > avg;
  print(ans);
}
