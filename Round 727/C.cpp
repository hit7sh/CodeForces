 
void solve() {
  ll n, k, s;
  cin >> n >> k >> s;
  vl A(n), barrier;
  cin >> A;
  sort(all(A));
  for(int i = 1; i < n; i++) {
      if(A[i] - A[i - 1] > s) {
          barrier.EB((A[i] - A[i - 1] - 1) / s);
      }
  }
 
  sort(rall(barrier));
 
  while(sz(barrier)){
    if (barrier.back() > k) break;
    k -= barrier.back();
    barrier.pop_back();
  }
 
  print(sz(barrier) + 1);
}
 
