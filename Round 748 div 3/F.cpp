int dp[41][41][41][41] = {};
//    [i][#red][#red % a][#black % b]
array<int, 3> par[41][41][41][41] = {};
 
void solve() {
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  memset(dp, 0x00, sizeof(dp));
  dp[0][0][0][0] = 1;
  f0(i, n) for (int nr = 0; nr <= i; nr++) f0(mr, a) f0(mb, b) if (dp[i][nr][mr][mb]) {
    // take red
    int nm = (mr * 10 + s[i] - '0') % a;
    dp[i + 1][nr + 1][nm][mb] = 1;
    par[i + 1][nr + 1][nm][mb] = {1, mr, mb};
 
    // take blue
    nm = (mb * 10 + s[i] - '0') % b;
    dp[i + 1][nr][mr][nm] = 1;
    par[i + 1][nr][mr][nm] = {0, mr, mb};
  }
 
  int t = 100000, who = -1;
  for (int i = 1; i < n; i++) {
    if (dp[n][i][0][0]) {
      if (cmin(t, abs(i - (n - i)))) {
        t = abs(i - (n - i));
        who = i;
      }
    }
  }
  if (who == -1) {
    print(-1);return;
  }
 
  string ans;
  int mr = 0, mb = 0;
  for (int i = n; i > 0; i--) {
    array<int, 3> x = par[i][who][mr][mb];
    ans.PB(x[0] == 1 ? 'R' : 'B');
    who -= x[0];
    mr = x[1];
    mb = x[2];
  }
  reverse(all(ans));
  // dbg(ans);
  print(ans);
}
