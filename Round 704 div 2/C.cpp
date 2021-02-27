 
void solve() {
	int n, m, i, j;
	string s, t;
	cin >> n >> m >> s >> t;
	vi c1(m), c2(m);
 
	for (i = 0, j = 0; i < n; i++) {
		if (j < m && s[i] == t[j]) {
			c1[j] = i;
			j++;
		}
	}
	
	for (i = sz(s)-1, j = sz(t) - 1; ~i; i--) {
		if (j >= 0 && s[i] == t[j]) {
			c2[j] = i;
			j--;
		}
	}
	
	
	int ans = 0;
	f0(i, m-1)
		cmax(ans, c2[i+1] - c1[i]);
	print(ans);
}
 
