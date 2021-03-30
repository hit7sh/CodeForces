void solve() {
	string a, b;
	cin >> a >> b;
	if (sz(a) > sz(b))
		swap(a, b);
	int sm, ms, i, j, k, n = sz(a), m = sz(b);
	ms = sm = 0;
	f0(i, n) {
		f0(j, m) {
			int l = 0;
			while (i + l < n && j + l < m && a[i + l] == b[j + l]) l++;
			cmax(ms, l);
		}
	}
	print(n+m-2*ms);
}	
 
