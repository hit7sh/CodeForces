string s;
 
int dp[12][2][2];
 
int f(int idx, int carry, int carry2) {
  if (idx < 0) {
    if (carry or carry2) return 0;
    return 1;
  }
  int &ans = dp[idx][carry][carry2];
  if (~ans) return ans;
  ans = 0;
 
  f0(d1, 10) f0(d2, 10) {
    int sm = d1 + d2 + carry;
    if (sm % 10 == s[idx] - '0') {
      ans += f(idx - 1, carry2, sm / 10);
    }
  }
  return ans;
}
 
 
void solve() {
  memset(dp, 0xff, sizeof(dp));
  cin >> s;
  print(f(sz(s) - 1, 0, 0) - 2);
}
