void compress(vector<int>& A) {
  vector<int> sorted = A;
  vector<int> compressed(A.size());
  sort(sorted.begin(), sorted.end());
  for (int i = 1; i < (int) A.size(); i++) {
    if (sorted[i] == sorted[i - 1])
      compressed[i] = compressed[i - 1];
    else
      compressed[i] = compressed[i - 1] + 1;
  }
  for (int i = 0; i < (int) A.size(); i++) {
    A[i] = compressed[lower_bound(sorted.begin(), sorted.end(), A[i]) - sorted.begin()];
  }
}
 
template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;
 
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
 
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};
 
void solve() {
  int n;
  cin >> n >> n;
  vi A(n);
  cin >> A;
  compress(A);
  // print(A);
 
  vi cnt(n);
  for (int x : A) cnt[x]++;
  vvi pos(n);
  for (int i = 0; i < n; i++) {
    pos[A[i]].EB(i);
  }
  vi S = A;
  sort(all(S));
  vvi npos(n);
  for (int i = 0; i < n; i++) {
    npos[S[i]].EB(i);
  }
 
  fenwick<int> ft(n + 1);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += ft.get(npos[A[i]].back());
    ft.modify(npos[A[i]].back(), 1);
    npos[A[i]].pop_back();
  }
  print(ans);
}
 
