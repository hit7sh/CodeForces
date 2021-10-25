void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  int c[2] = {};
  for (int x : A) if (x < 2) c[x]++;
 
  print(((1LL * c[1]) << c[0]));
}
 
