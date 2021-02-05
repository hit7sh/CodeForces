bool good(vi& A, ll ad, ll k) {
	ll s = ad + A[0], i;
	f1(i, sz(A)-1) {
		if (100LL*A[i] > s*k)
			return false;
		s += A[i];
	}
	return true;
}
 
 
 
 
void solve() {
	int i, j, n, k;
	cin >> n >> k;
	vi A(n);
	cin >> A;
 
	ll L = 0, R = 1e12, M;
 
	while (L < R) {
		M = (L+R)/2;
 
		if (good(A, M, k))
			R = M;
		else
			L = M + 1;
	}
	print(L);
}
 
