void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
 
  deque<int> dq;
  dq.push_back(A[0]);
  for (int i = 1; i < n; i++) {
    if (A[i] < dq.front())
      dq.push_front(A[i]);
    else dq.push_back(A[i]);
  }
  for (int x : dq) cout << x << ' ';
  cout << '\n';
}
 
