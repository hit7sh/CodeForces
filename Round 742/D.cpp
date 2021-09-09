void solve() {
  int S, N;
  cin >> S >> N;
 
  while (N > 1) {
    ll r = 100000000000;
    while (S - r < N - 1) r /= 10;
    S -= r;
    cout << r << ' ';
    N--;
  }
 
  if (N) cout << S << ' ';
  cout << '\n';
}
 
