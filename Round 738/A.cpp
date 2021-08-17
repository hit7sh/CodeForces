void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  int ans = -1;
  for (int x : A) ans &= x;
    print(ans);
}
