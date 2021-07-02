 
void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  sort(all(A));
  vl pref(n);
  pref[0] = A[0];
  
  for (int i = 1; i < n; i++)
    pref[i] += pref[i - 1] + A[i];
 
  ll sm = 0, ans = 0, c = 1;
  for (int i = 0; i + 2 < n; i++) {
    ans += pref[i] - A[i + 2] * 1LL * c++;
  }
 
  print(ans);
}
