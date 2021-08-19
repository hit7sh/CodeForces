int digits(int i){
  int z = 0;
  int c = i;
  while(c){
    z |= (1 << (c % 10));
    c /= 10;
  }
  return __builtin_popcount(z);
}
 
void solve() {
  int n, k;
  cin >> n >> k;
  while (digits(n) > k) {
    int r = 1, c = n;
    while (digits(c) > k) {
      c /= 10;
      r *= 10;
    }
    r /= 10;
    n = ((n / r) + 1) * r;
  }
  print(n);
}
