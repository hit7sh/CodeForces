
void solve() {
  int n;
  cin >> n;
 
  set<pii> st;
  int cnt[2] = {};
 
  auto ask = [&](int x) {
    cout << "? " << x << endl;
    vi dist(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> dist[i];
      if (dist[i] == 1)
        st.emplace(min(i, x), max(i, x));
    }
    return dist;
  };
 
  vi A = ask(1);
 
  for (int i = 1; i <= n; i++)
    cnt[A[i] % 2]++;
 
  int u = cnt[0] > cnt[1] ? 1 : 0;
 
  for (int i = 2; i <= n; i++)
    if (A[i] % 2 == u)
      ask(i);
 
  cout << "!\n ";
  for (auto x: st)
    print(x);
}
