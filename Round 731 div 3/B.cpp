void solve() {
  string s;
  cin >> s;
  int L = -1, R = -1, n = sz(s);
  for (int i = 0; i < n; i++) 
    if (s[i] == 'a')
      L = R = i;
  if (L == -1) {
    cout << "No\n";
    return;
  }
  char to = 'b';
  while (R - L + 1 != n) {
    if (L - 1 >= 0 && s[L - 1] == to) {
      L -= 1;
      to++;
    } else if (R + 1 < n && s[R + 1] == to) {
      R += 1;
      to++;
    } else {
      Yes(0);
      return;
    }
  }
  Yes(1);
}
 
