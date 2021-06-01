void solve() {
  int n;
  cin >> n;
  vi A(n);
  cin >> A;
  if (is_sorted(all(A))) {
    print(0); 
  } else if ((A.front() == 1 or A.back() == n)) {
    print(1);
  } else if (A.front() != n or A.back() != 1) {
    print(2);
  } else {
    print(3);
  }
  
}
