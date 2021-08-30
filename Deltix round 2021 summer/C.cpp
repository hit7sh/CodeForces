void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  ll ans = 0;
  for (int i = 0; i < n; i += 2) { // i is (
    ll cur = A[i], mn = A[i];
    for (int j = i + 1; j < n; j++) {
      if (j & 1) {
        // )
        // cur = number of ( so far that are not balanced
        // mn = minimum # of ( not balanced so far from i till j
        // if we encounter a closing bracket
        ll L = max(0LL, cur - A[j]), R = min({mn, cur - 1, A[i] - 1LL});
        if (L <= R) ans += R - L + 1;
      }
 
      if (j % 2 == 0) cur += A[j];
      else cur -= A[j];
 
      mn = min(mn, cur);
    }
  }
  print(ans);
}
