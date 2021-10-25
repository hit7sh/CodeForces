void solve() {
  int n, k;
  cin >> n >> k;
  vi A(k);
  cin >> A;
  sort(all(A));
  int cat = 0, i = 0, j = k - 1, ans = 0;
  while (j >= 0 && cat < A[j]) {
    int to = n - A[j];
    ans++;
    cat += to;
    while (i < j && A[i] <= cat) i++;
    j--;
  }
  print(ans);
}
