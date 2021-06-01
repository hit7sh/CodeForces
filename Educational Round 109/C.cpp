void solve() {
  int n, m;
  cin >> n >> m;
  vi A(n), order(n);
  vector<char> D(n);
  cin >> A >> D;
  iota(all(order), 0);
  sort(all(order), [&](int a, int b) {
    return A[a] < A[b];
  });
  
  vi a, b, ans(n, -1);
  for (int& i : order) {
    if (A[i] & 1) {
      if (D[i] == 'L') {
        if (!a.empty()) {
          ans[i] = a.back();
          ans[a.back()] = i;
          a.pop_back();
          continue;
        }
        a.push_back(i);
        continue;
      }
      a.push_back(i);
    } else{
     if (D[i] == 'L') {
      if (!b.empty()) {
        ans[i] = b.back();
        ans[b.back()] = i;
        b.pop_back();
        continue;
      }
      b.push_back(i);
      continue;
     }
     b.push_back(i); 
    }
  }
 
  while (sz(b) >= 2) {
    int i = b.back(); b.pop_back();
    int j = b.back(); b.pop_back();
    ans[i] = j;
    ans[j] = i;
  }
 
  while (sz(a) >= 2) {
    int i = a.back(); a.pop_back();
    int j = a.back(); a.pop_back();
    ans[i] = j;
    ans[j] = i;
  }
 
  for (int i = 0; i < n; i++) {
    if (ans[i] == -1) {
      cout << "-1 ";
      continue;
    }
    int from = i, to = ans[i];
 
    if (A[from] > A[to]) swap(from, to);
 
    if (D[from] == 'R' && D[to] == 'L') 
      cout << abs(A[to] - A[from]) / 2 << ' ';
    else if (D[from] == 'L' && D[to] == 'L')
      cout << (A[from] + A[to]) / 2 << ' ';
    else if (D[from] == 'R' && D[to] == 'R')
      cout << (2 * m - A[from] - A[to]) / 2 << ' ';
    else cout << (2 * m + A[from] - A[to]) / 2 << ' ';
  }
  cout << endl;
}
