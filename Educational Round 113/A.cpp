void solve() {
  int n;
  string s;
  cin >> n >> s;
  string b = s;
  sort(all(b));
  if (b.back() == b.front()) print("-1 -1");
  else {
    for (int i = 0; i + 1< n; i++) {
      if (s[i] ^ s[i + 1]) {
        print(i + 1, i + 2);
        return;
      }
    }
  }
}
 
