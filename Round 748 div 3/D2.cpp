template<typename T>
std::vector<T> divisors(T n) {
  std::vector<T> divisors;
  for (int i = 1; (T) i * i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (i != n / i) {
        divisors.push_back(n / i);
      }
    }
  }
  return divisors;
}
 
void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  sort(all(A));
 
  f0(i, n) if (int(UB(all(A), A[i]) - LB(all(A), A[i])) >= n / 2) {
    print(-1);
    return;
  }
  int ans = 0;
  f0(i, n) for (int j = i + 1; j < n; j++) {
    int dif = abs(A[i] - A[j]);
    if (dif == 0) continue;
    auto D = divisors(dif);
    for (int k : D) {
      int c = 0;
      f0(p, n) {
        c += abs(A[p] - A[i]) % k == 0;
      }
      if (c >= n / 2) {
        cmax(ans, k);
      }
    }
  }
  print(ans);
}
 
