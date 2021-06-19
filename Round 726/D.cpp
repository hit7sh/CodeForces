void solve() {
  int n;
  cin >> n;
  if (n & 1 or (__builtin_popcount(n) == 1 && __builtin_ctz(n) & 1))
    print("Bob");
  else print("Alice");
}
