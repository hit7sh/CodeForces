void solve() {
  string s;
  cin >> s;
  int n = sz(s);
  int ca = count(all(s), 'A'), cc = count(all(s), 'C'), cb = n - ca - cc;
  Yes(cb == ca + cc);
}
 
