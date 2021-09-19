void solve() {
  int n;
  cin >> n;
  vi A(n), B(n);
  cin >> A >> B;
  mii id1, id2;
  f0(i, n) id1[A[i]] = i, id2[B[i]] = i;
  // A : 1 3 5 7 ..
  // B : 2 4 6 8 ..
  int j = -1;
  f0(i, n) {
    while (j + 2 < B[i]) id1[j += 2] = i;
  }
  int ans = INF;
  f0(i, n) {
    cmin(ans, id1[A[i]] + i);
  }
  print(ans);
}
