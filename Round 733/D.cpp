void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  A.insert(A.begin(), 0);
  vi ans(n + 1), vis(n + 1);
  int c = 0;
  f1(i, n) {
    if (!vis[A[i]]) {
      c++;
      vis[A[i]] = 1;
      ans[i] = A[i];
    }
  }
  print(c);
  int j = n;
  f1(i, n) {
    if (!ans[i]) {
      while (vis[j]) j--;
 
      ans[i] = j;
      j--;
    }
  }
 
  f1(i, n) {
    if (ans[i] == i) {
      ans[i] = A[i];
      f1(j, n) {
        if (j != i && ans[j] == A[i]) {
          ans[j] = i;
        }
      }
    }
  }
  ans.erase(ans.begin());
  print(ans);
}
