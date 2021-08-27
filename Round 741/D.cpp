void solve() {
  int n, q, L, R;
  cin >> n >> q;
  string s;
  cin >> s;
  s = " " + s;
  for (int i = 2; i <= n; i += 2) {
    s[i] ^= '+' ^ '-';
  }
  vi pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = (s[i] == '+' ? 1 : -1) + pref[i - 1];
  }
  vvi pos(2 * n + 1);
  f1(i, n) {
    pos[n + pref[i]].EB(i);
  }
 
  while (q--) {
    cin >> L >> R;
    int x = pref[R] - pref[L - 1];
   if (x == 0) cout << "0\n";
   else if (x & 1) { 
     cout <<"1\n";
     int target = (x < 0 ? (x - 1) / 2 : (x + 1) / 2) + pref[L - 1]; 
     auto it = LB(all(pos[n + target]), L);
     cout << *it << '\n';
    } else {
     cout << "2\n";
     int target = x / 2 + pref[L - 1];
     auto it1 = LB(all(pos[n + target]), L);
     target = x + pref[L - 1];
     auto it2 = LB(all(pos[n + target]), L);
     cout << *it1 << ' ' << *it2 << '\n';
    }
  }
}
