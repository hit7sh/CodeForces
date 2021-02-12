  void solve() {
  ll n, i, from , to, reached, ans;
  cin >> n;
  vl T(n), X(n);
  f0(i, n) cin >> T[i] >> X[i];
  T.EB(1e15);
  from = to = ans = 0;

  f0(i, n) {
  	if (from == to)
  		to = X[i];

  	if (T[i+1] - T[i] >= abs(from - to))
  		reached = to;
  	else
  		reached = from < to ? from + T[i+1] - T[i] : from - ( T[i+1] - T[i]);

  	ans += (X[i] - from)*(X[i] - reached) <= 0; // increment ans if X[i] lies between from and reached(bw T[i] and T[i+1])

  	from = reached;
  }
  print(ans);
}
