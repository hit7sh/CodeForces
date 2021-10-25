void solve() {
  string s;
  cin >> s;
  int n = sz(s);
  vector<bool> has(26);
  for (char x : s) has[x - 'a'] = 1;
    char a;
  string b;
  f0(i, 26) if (has[i]) { a = i + 'a'; break; }
  bool found = 0;
  f0(i, n) {
    if (!found && s[i] == a) found = 1;
    else { b += s[i]; }
  } 
  print(a, b);
}
