void solve() {
  int n;
  cin >> n;
  if (n < 10) {
    f0(i, n) cout << char('a' + i);
    cout << endl;
  } else {
    string bet = "b";
    if (n & 1) bet += "c", n -= 1;
    n /= 2;
    print(string(n, 'a') + bet + string(n - 1, 'a'));
  }
}
 
