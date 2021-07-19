void solve() {
  int n;
  cin >> n;
  vi A(n), B(n);
  cin >> A >> B;
  sort(rall(A));
  sort(rall(B));
  A.insert(A.begin(), 0);
  B.insert(B.begin(), 0);
  for (int i = 1; i <= n; i++) {
    A[i] += A[i - 1];
    B[i] += B[i - 1];
  }
  int L = -1, R = 1e6, M;
  ll v1, v2;
 
  while (R - L > 1) {
    M = (L + R) / 2;
    int take = n + M - (n + M) / 4;
    v1 = min(M, take) * 100;
    v2 = B[min(n, take)];
    take -= min(M, take);
    v1 += A[take];
 
    if (v1 >= v2)
      R = M;
    else L = M;
  }
  print(R);
}
 
