void solve() {
  int n;
  cin >> n;
  string s;
  f0(i, 2 * n) {
    s += (i % 2 == 0 ? "(" : ")");
  }
  int f = 1;
  string t;
  f0(i, n) {
    t = string(i + 1, '(') + string(i + 1, ')');
    s.pop_back();
    s.pop_back();
    print(t + s);
  }
}
