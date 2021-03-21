 
void solve() {
	int n, m, i, j, k, l;
	cin >> n;
	vl A(n);
	cin >> A;
	ll s1 = 0, s2 = 0, m1 = INF, m2 = INF, c1 = 0, c2 = 0, ans = LINF;
	for (i = 0; i < n; i++) {
		if (~i & 1) {
			s1 += A[i];
			m1 = min(m1, A[i]);
			c1++;
		} else {
			s2 += A[i];
			m2 = min(m2, A[i]);
			c2++;
		}
		ans = min(ans, s1 + (n - c1)*m1 + s2 + (n - c2)*m2);
	}
	print(ans);
}	
 
