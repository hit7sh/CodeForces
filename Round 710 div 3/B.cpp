 
void solve() {
	string s;
	int n, k, i, ans = 0;
	cin >> n >> k;
	cin >> s;
	vi pos;
	f0(i, n)
		if (s[i] == '*')
			pos.EB(i);
 
	int m = sz(pos);
	vi used(m);
	used[0] = 1;
	f0(i, m) {
		if (used[i]) {
			int next = upper_bound(pos.begin(), pos.end(), pos[i] + k) - pos.begin() - 1;
	        used[next] = 1;
	        ans++;
		}
	}
	// print(used);
	print(ans);
}	
 
