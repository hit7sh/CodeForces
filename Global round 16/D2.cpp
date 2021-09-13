void solve() {
  int n, m;
  cin >> n >> m;
 
  vector<pii> A(n * m);
 
  f0(i, n * m) cin >> A[i].F, A[i].S = i;
 
  sort(all(A));
  int ans = 0;
  f0(i, n) {
    sort(A.begin() + i * m, A.begin() + i * m + m, [](pii& x, pii& y) {
      if (x.F != y.F) return x.F < y.F;
      return x.S > y.S;
    });
 
    f0(j, m) {
      f0(k, j) {
        ans += A[i * m + j].S > A[i * m + k].S; 
      }
    }
  }
  print(ans);
}
