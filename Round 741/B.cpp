const int P[] = {2, 3, 5, 7};
 
void solve() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  string ans;
  int cnt[10] = {}, who, mxc = 0, found = -1;
  for (char x : s) {
    int xx = x - '0';
    if (!binary_search(P, P + 4, xx))
      found = xx;
    cnt[xx]++;
    if (cmax(mxc, cnt[xx]))
      who = xx;
  }
  if (~found) {
    cout << 1 << '\n' << found << endl;
  } else if (mxc > 1) {
    cout << 2 << '\n' << string(2, who + '0') << endl;
  } else {
    for (int mask = 1; mask < 1 << k; mask++) {
      int now = 0, c = 0;
      f0(i, k) {
        if (mask & 1 << i)
          now = now * 10 + s[i] - '0', c++;
      }
      if (!_prime(now)) {
        cout << c << '\n' << now << '\n';
        return;
      }
    }
  }
}
