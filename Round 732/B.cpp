 
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> B(n), A(n - 1);
  cin >> B >> A;
  vi s0(m), s1(m);
  for (string& s : B) {
    for (int i = 0; i < m; i++)
      s0[i] += s[i] - 'a'; 
  }
  for (string& s : A) {
    for (int i = 0; i < m; i++)
      s1[i] += s[i] - 'a';
  }
  for (int i = 0; i < m; i++) {
    cout << char(s0[i] - s1[i] + 'a');
  }
  cout << endl << flush;
}
 
