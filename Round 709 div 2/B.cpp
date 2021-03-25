 
 
void solve() {
	int n, i;
	cin >> n;
	vl A(n);
	cin >> A;
	
	set<int> s;
	for (i = 0; i < n-1; i++) {
		s.insert(A[i+1] - A[i]);
	}
	
	if (sz(s) > 2) {
		print(-1);
	} else if (sz(s) <= 1) {
		print(0);
	} else {
	
		ll x = *s.begin();
		ll y = *s.rbegin();
		ll m = abs(x-y);
		if (*max_element(all(A)) >= m) {
			print(-1);
			return;
		}
		print(m, max(x, y));
	}
}
