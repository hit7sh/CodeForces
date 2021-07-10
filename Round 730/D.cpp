int sub(int a, int b, int k){
  int ans = 0, m = 1;
  while (a > 0 || b > 0){
    int r = (a + k - b % k) % k;
    ans += m * r;
    m *= k;
    a /= k;
    b /= k;
  }
  return ans;
}
 
void solve() {
  int n, k, r;
  cin >> n >> k;
  vi A(n + 1);
  for (int i = 1; i <= n; i++) {
    if (i & 1)
      A[i] = sub(i - 1, i, k);
    else
      A[i] = sub(i, i - 1, k);
  }
  
  for (int i = 0; i < n; i++) {
    cout << A[i] << '\n' << flush;
    cin >> r;
    if (r == 1)
      break;
  }
} 
 
