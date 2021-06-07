void solve() {
  int n; cin >> n;
  string s;
  cin >> s;
  vi vis(26);
  for (char& x : s)
    vis[x - 'a'] = 1;
  for (int i = 0; i < 26; i++) {
    if (!vis[i]) {
      print(char('a' + i));
      return;
    }
  }
 
  set<string> st;
  for (int i = 0; i < n - 1; i++) {
    string t = s.substr(i, 2);
    st.insert(t);
  }
  string t = "aa";
  for (string x : st) {
    if (x != t) {
      print(t);
      return;
    }
    if (t[1] == 'z') t[0] += 1, t[1] = 'a';
    else t[1] += 1;
  }
  st.clear();
  for (int i = 0; i < n - 2; i++) {
    string t = s.substr(i, 3);
    st.insert(t);
  }
  t = "aaa";
  for(string x : st) {
    if (x != t) {
      print(t);
      return;
    }
    if (t[1] == 'z') t[0] += 1, t[1] = 'a', t[2] = 'a';
    else if (t[2] == 'z') t[1] += 1, t[2] = 'a';
    else t[2] += 1;
  }
}
