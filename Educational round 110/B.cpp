void solve() {
 int n;
 cin >> n;
 vi A(n);
 for (int& x : A) cin >> x;
 sort(all(A), [](int a, int b) {
  return a % 2 < b % 2;
 });
 ll ans = 0;
 
 for (int i = 0; i < n; i++) {
  if (A[i] % 2 == 0) 
    ans += n - i - 1;
  else {
    int cnt = 0;
    for (int j = i + 1; j < n; j++) {
      if (gcd(A[i], A[j]) > 1)
        cnt++;
    }
    ans += cnt;
  }
 }
 print(ans);
}
 
