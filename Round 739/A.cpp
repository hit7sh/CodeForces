vi res;
 
void solve() {
  int k;
  cin >> k;
  print(res[k - 1]);
}
 
bool check(int n) {
  if (n % 3 == 0 or n % 10 == 3) return 0;
  return 1;
}
 
int main() {
  for (int i = 1; i <= 1e4; i++) {
    if (check(i)) res.EB(i);
  }
  precision __speed() TC solve(); return 0; 
}
