void solve() {
  int n, m;
  cin >> n >> m;
  vi vis(n + 1);
  f0(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    vis[b] = 1;
  }
  int who = -1;
  f1(i, n) if (!vis[i]) who = i;
 
  assert(~who);
  f1(i, n) if (i ^ who) print(who, i);
}
 
