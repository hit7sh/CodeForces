vector<mi> p2(200200);
 
void solve() {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    print(1);
    return;
  }
 
  if (n % 2 == 0) {
    mi ans = pow(p2[n - 1] - 1, k);
    for (int i = 1; i <= k; i++) {
      ans += pow(p2[n - 1] - 1, i - 1) * pow(p2[n], k - i);
          //  even #1s except all 1   | | anything
    }
    print(ans);
  } else {
    mi ans = 0; // all 1;
    ans += pow(p2[n - 1], k); // all 0
    for (int i = 1; i <= k; i++) {
      // on ith bit is on in &
      ans += pow(p2[n - 1], i - 1) * (pow(1 + p2[n - 1], k - i)); // correct
    }
    print(ans);
  }
}
