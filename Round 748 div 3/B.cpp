void solve() {
  string s;
  cin >> s;
  ll n = stoll(s);
 
  // last 2 digits : 00, 25, 50, 75
 
  reverse(all(s));
  vector<string> to = {"00", "52", "05", "57"};
  int ans = INF;
  for (string& x : to) {
    bool can = 1;
    int f = -1, l = -1, moves = 0;
    for (char c : s) {
      moves++;
      if (l == -1 && f == -1 && c == x[0]) f = 1, moves--;
      else if (f == 1 && l == -1 && c == x[1]) {l = 1; moves--; break;}
    }
    if (f == 1 && l == 1) cmin(ans, moves);
  }
  print(ans);
}
 
