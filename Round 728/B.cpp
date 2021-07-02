void solve() {
  int n, ans = 0;
  cin >> n;
  vi A(n + 1);
  vi loc(2 * n + 1, -1);
  for (int i = 1; i <= n; i++) 
    cin >> A[i], loc[A[i]] = i;
  
  vector<pii> R(n + 1);
  int c = 0;
  for (int i = 2; i <= n; i++) {
    R[i].F = i + 1, R[i].S = i + 1 + c++;
  }
 
  for (int i = 3; i < 2 * n; i++) {
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0 && i - j * j != 0 && ~loc[j] && ~loc[i / j])
        ans += loc[j] + loc[i / j] == i;
    }
  }
 
  print(ans);
}
