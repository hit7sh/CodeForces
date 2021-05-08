int ft[200005];
void upd(int i, int v) {
	for(;i <= mxN; i += i&-i) // i += i&-i goes to the parent segment
		ft[i] += v;
}
 
int get(int r) {	// returns query[1, r]
	int res = 0;
	for(; r>0; r -= r&-r) // i -= i&-i goes to child segment
		res += ft[r];
	return res;
}
 
vi mem;
int A[] = {1,3 ,4 ,5 };
int query(int l, int r) {
	#ifndef ONLINE_JUDGE
	int ans = 0;
	for (int i = l; i <= r; i++) ans += A[i];
		return ans;
	#else
	if (~mem[r]) return (mem[r] + get(r));
	cout << '?' << ' '  << l << ' ' << r << endl;
	int a;
	cin >> a;
	mem[r] = a - get(r);
	return a;
	#endif
}
 
void solve() {
	int n, t, k;
	cin >> n >> t;
	mem = vi(n + 1, -1);
	while (t--) {
		cin >> k;
		int L = 1, R = n, M;
		
		while (L < R) {
			M = (L + R) / 2;
			// print(L, M, R);
			if (M - query(1, M) >= k)
				R = M;
			else
				L = M + 1;
		}
		cout << '!' << ' ' << L << endl;
		upd(L, +1);
	}
}
 
