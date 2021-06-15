vi A;
int ff(int x) {
  int c = 0;
  for (int i = 0; i < sz(A); i++) {
    ++c;
    if (A[i] == x)
      return c;
  }return c;
}
 
int bb(int x) {
  int c = 0;
  for (int i = sz(A) - 1; ~i; --i) {
    ++c;
    if (A[i] == x)
      return c;
  }
  return c;
}
 
void solve() {
  int n;
  cin >> n;
  A = vi(n);
  cin >> A;
  int mn = *min_element(all(A)), mx = *max_element(all(A));
  
  print(min({max(ff(mn), ff(mx)), max(bb(mn), bb(mx)), min(ff(mx) + bb(mn), bb(mx) + ff(mn))}));
 
}
 
