void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  int ans = 0;
  f0(j, 10000) {
    if (is_sorted(all(A))) break;
    ans++;
    for (int i = (j & 1); i + 1 < sz(A); i += 2) {
      if (A[i] > A[i + 1])
        swap(A[i], A[i + 1]);
    }
  }
  print(ans);
}
