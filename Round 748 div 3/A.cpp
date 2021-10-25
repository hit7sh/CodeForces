void solve() {
  int n = 3;
  vi A(n); 
  cin >> A;
  f0(i, n) {
    int to = 0;
    f0(j, n) if (i ^ j) {
      cmax(to, max(0, A[j] - A[i] + 1));
    }
    cout << to << ' ';
  }
  cout << endl;
}
