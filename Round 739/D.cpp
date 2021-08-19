string p2[60] = {};
 
int where(string from, char to, int pos) {
  for (int i = pos; i < sz(from); i++) {
    if (from[i] == to) return i;
  }
  return -1;
}
int check(string from, string to) {
  int n = sz(from), m = sz(to);
  int i = 0, j = 0, found = 0;
  while (i < n && j < m && where(from, to[j], i) != -1) {
    found++;
    i = where(from, to[j], i) + 1;
    j++;
  }
  // dbg(found);
  return n - found + (m - found);
}
 
void solve() {
  string k;
  cin >> k;
  int ans = INF;
  f0(i, 60) {
    cmin(ans, check(k, p2[i]));
  }
  print(ans);
}
