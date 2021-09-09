 
void solve() {
  int n;
  string s;
  cin >> n >> s;
 
  string ans;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') ans += 'D';
    else if (s[i] == 'D') ans += 'U';
    else ans += s[i];
    // dbg(ans);
  }
  print(ans);
}
