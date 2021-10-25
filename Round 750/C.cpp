
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int ans = INF;
  for (char x = 'a'; x <= 'z'; x++) {
    int L = 0, R = n - 1, cnt = 0;
 
    while (L < R) {
      if (s[L] == s[R]) L++, R--;
      else if (s[L] == x) L++, cnt++;
      else if (s[R] == x) R--, cnt++;
      else { cnt = INF; break; }
    }
    cmin(ans, cnt);
  }
  if (ans == INF) ans = -1;
  print(ans);
}
 
