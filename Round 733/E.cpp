void solve() {
  string s;
  cin >> s;
  set<int> st(all(s));
  if (sz(st) == 1) {
    print(s);
  } else {
    vi cnt(26);
    for (char& x : s) cnt[x - 'a']++;
 
    bool has1 = 0;
    int v = -1;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] == 1) {
        has1 = 1;
        v = i;
        break;
      }
    }
 
    if (has1) {
      cout << char(v + 'a');
      cnt[v]--;
      f0(i, 26) {
        while (cnt[i]--)
          cout << char(i + 'a');
      }
    } else {
      int x = 0;
      while (x < 26 && cnt[x] == 0) x++;
      // x is smallest
      if (cnt[x] <= sz(s) / 2 + 1) {
        // aa...
        cout << char(x + 'a');
        cnt[x]--;
 
        for (; cnt[x] > 0; ) {
          cout << char(x + 'a');
          cnt[x]--;
          for (int i = x + 1; i < 26; i++) {
            if (cnt[i] > 0) {
              cout << char(i + 'a');
              cnt[i]--;
              break;
            }
          }
        }
        f0(i, 26) {
          for (; cnt[i] > 0; cnt[i]--)
            cout << char(i + 'a');
        }
      } else {
        //ac....
        if (sz(st) == 2) {
          int y = x + 1;
          while (cnt[y] == 0) y++;
 
          cout << char(x + 'a');
          cnt[x]--;
          cout << string(cnt[y], y + 'a');
          cout << string(cnt[x], x + 'a');
        } else {
          int y = x + 1;
          while (cnt[y] == 0) y++;
          int z = y + 1;
          while (cnt[z] == 0) z++;
 
          cout << char(x + 'a') << char(y + 'a');
          cnt[x]--, cnt[y]--;
          cout << string(cnt[x], x + 'a');
          cnt[x] = 0;
          cout << char(z + 'a');
          cnt[z]--;
          f0(i, 26) {
            while (cnt[i]--) {
              cout << char(i + 'a');
            }
          }
        }
      }
    }
  }
  cout << endl;
}
