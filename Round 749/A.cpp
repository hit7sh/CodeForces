void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  int sm = accumulate(all(A), 0);
  if (!_prime(sm)) {
    print(n); f1(i, n) cout << i << ' ';
    cout << '\n';
  } else {
    int who = -1, mx = 0;
    f0(i, n) if (!_prime(sm - A[i])) {
      if (cmax(mx, sm - A[i])) who = i;
    }
    print(n - 1);
    f0(i, n) if (i ^ who) cout << i + 1 << ' ';
    cout << '\n';
  }
}
