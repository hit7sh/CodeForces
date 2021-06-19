void solve() {
  ll n, m, x, y;
  cin >> n >> m >> x >> y;
  ll dist = -1;
 
  int i, j;
  pii a, b;
  pair<int, int> pos[4] = {{1, 1}, {n, 1}, {1, m}, {n, m}};
 
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ll d1 = abs(pos[i].F - x) + abs(pos[i].S - y), d2 = abs(pos[j].F - x) + abs(pos[j].S - y);
      if (d1 > d2) swap(d1, d2);
      ll cur = d1;
 
      cur += abs(pos[i].F - pos[j].F) + abs(pos[i].S - pos[j].S);
 
      if (cmax(dist, cur)) {
        a = pos[i], b = pos[j];
      }
    }
  }
  print(a, b);
}
 
