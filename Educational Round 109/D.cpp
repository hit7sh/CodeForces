ll dp[2501][5001];
ll A[5001];
vi pos;
ll f(ll k, ll n) {
  if (k < 0) return 0;
  if (n < 0) return LINF;
  ll& ans = dp[k][n];
  if (~ans) return ans;
 
  if (A[n]) {
    return ans = f(k, n - 1);
  } else {
    return ans = min(abs(pos[k] - n) + f(k - 1, n - 1), f(k, n - 1));
  }
}

void solve() {
  memset(dp, 0xff, sizeof(dp));
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (A[i]) pos.EB(i);
  }
  int x = sz(pos);
  print(f(x - 1, n - 1));
}
 
 
