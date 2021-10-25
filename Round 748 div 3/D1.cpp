void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  
  int mx = *max_element(all(A));
  int ans = 1;
  sort(all(A));
  if (A[0] == A[n - 1]) {
    print(-1);return;
  }
  vi dif;
  f0(i, n) f0(j, n) if (i ^ j) if (A[i] != A[j]) dif.EB(abs(A[i] - A[j]));
  sort(all(dif));
  dif.erase(unique(all(dif)), dif.end());
  mx = *max_element(all(dif));
 
  int l = 0;
  for (int i : dif) {
    l = gcd(l, i);
  }
  print(l);
}
