void solve() {
  int n, k;
  cin >> n >> k;
  vi OR(n + 1);
  vi AND(n + 1);
  vi XOR(n + 1);
  vi A(n + 1);
  for (int i = 2; i <= n; i++) {
    int t;
    cout << "or " << i - 1 << ' ' << (i) << '\n' << flush;
    cin >> t;
    // t = T[i] | T[i - 1];
    OR[i] = t;
    cout << "and " << i - 1 << ' ' << (i) << '\n' << flush;
    cin >> t;
    // t = T[i] & T[i - 1];
    AND[i] = t;
    XOR[i] = OR[i] - AND[i];
  }
 
  // 2 more queries
  int or13, and13;
  cout << "or " << 1 << ' ' << 3 << '\n' << flush;
  cin >> or13;
  // or13 = T[1] | T[3];
  cout << "and " << 1 << ' ' << 3 << '\n' << flush;
  cin >> and13;
  // and13 = T[1] & T[3];
  int xor13 = or13 - and13;
  int a = OR[2] + AND[2];
  int b = or13 + and13;
  int c = OR[3] + AND[3];
  // print(a, b, c);
  // a + b + 0 = k1
  // a + 0 + c = k2
  // 0 + b + c = k3
  A[2] = (a - b + c) / 2;
  A[3] = b - a + A[2];
  A[1] = b - A[3];
  for (int i = 4; i <= n; i++) {
    A[i] = XOR[i] ^ A[i - 1];
  }
  sort(all(A));
  cout << "finish " << A[k] << flush;
}
