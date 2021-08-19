void solve() {
  string s; 
  cin >> s;
  vi lst(26, -1), cnt(26);
  f0(i, sz(s)) lst[s[i] - 'a'] = i, cnt[s[i] - 'a'] += 1;
  vector<pii> ord;
  f0(i, 26) {
    if (~lst[i]) {
      ord.EB(lst[i], i);
    }
  }
  sort(all(ord));
  int len = 0;
  string t, og;
 
  f0(i, sz(ord)) {
    len += cnt[ord[i].S] / (i + 1);
  }
  f0(i, len) og += s[i];
  string here, temp = og, order;
  f0(i, sz(ord)) {
    // dbg(temp);
    order += ord[i].S + 'a';
    here += temp;
    string nxt;
    for (char x : temp) if (x - 'a' != ord[i].S) nxt += x;
    temp = nxt;
  }
  if (here != s) print(-1);
  else {
    print(og, order);
  }
  // we have found original string
  // now check if it is actually possible
}
