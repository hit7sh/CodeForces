void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  set<int> st = {-INF, +INF};
  st.insert(A[0]);
  auto M = next(st.begin());
 
  for(int i = 1; i < n; i++) {
    if (A[i] < *prev(M) or A[i] > *next(M)) {
      cout << "No" << endl;
      return;
    }
    st.insert(A[i]);
    M = st.find(A[i]);
  }
  cout << "Yes" << endl;
}
 
