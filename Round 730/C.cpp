const double eps = 1e-8;
 
double dfs(double c, double m, double p, double v) {
  double ans = 1;
  for (int i = 0; i < 2; i++) {
    if (c > eps) {
      double e = min(c, v);
      double nc = c - v;
      double np, nm;
      if (m < eps) {
        np = p + e;
        nm = m;
      } else {
        np = p + e / 2;
        nm = m + e / 2;
      }
      ans += c * dfs(nc, nm, np, v);
    }
    swap(c, m);
  }
  return ans;
}
 
void solve() {
  double c, m, p, v;
  cin >> c >> m >> p >> v;
  print(dfs(c, m, p, v));
} 
