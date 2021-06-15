int count(string s) {
  int res = 0;
  for (int i = 0; i < sz(s); i++) 
    res += s.substr(i, 4) == "haha";
  return res;
}
 
struct funny {
  string pref, suf;
  ll cnt = 0;
  funny(){}
  funny(const string &s) {
    cnt = count(s);
    pref = s.substr(0, 3);
    suf = s.substr(max(0, (int)s.size() - 3), s.size());
  }
};
 
 
funny add(funny a, funny b) {
  funny res;
  res.cnt = a.cnt + b.cnt;
  res.cnt += count(a.suf + b.pref);
  res.pref = a.pref;
  res.suf = b.suf;
 
  if (res.pref.size() < 3) {
    res.pref += b.pref;
    if (res.pref.size() > 3)
      res.pref.resize(3);
  }
  if (res.suf.size() < 3) {
    res.suf = a.suf + b.suf;
    if (res.suf.size() > 3)
      res.suf = res.suf.substr(res.suf.size() - 3, res.suf.size());
  }
  return res;
}
 
void solve() {
  map<string, funny> mp;
  int n;
  string v, a, b, op;
  for (cin >> n; n--;) {
    cin >> v >> op;
    if (op == ":=") {
      cin >> a;
      mp[v] = funny(a);
    } else {
      cin >> a >> b >> b;
      mp[v] = add(mp[a], mp[b]);
    }
    if (n == 0) {
      print(mp[v].cnt);
      return;
    }
  }
}
 
 
