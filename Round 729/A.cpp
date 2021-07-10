void solve() {
  int n;
  cin >> n;
  vi A(2 * n);
  cin >> A;
  vi cnt(2);
  for (int& x : A)
    cnt[x & 1]++;
 
  Yes(cnt[1] == cnt[0]);
} 
 
