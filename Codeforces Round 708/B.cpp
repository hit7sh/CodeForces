 
void solve() {
	int n, m;
	cin >> n >> m;
	vi A(n);
	cin >> A;
	map<int, vi> mp;
	mii done;
	for (int& x : A) {
		mp[x % m].EB(x);
		done[x % m] = done[m - x % m] = 0;
	}
	int ans = 0, g;
	for (auto & [x, y] : mp) {
		if ((done[m - x] && done[x]) or sz(y) == 0)
			continue;
		else if (m - x == x or x == 0) {
			ans++; 
		} else if (sz(mp[m-x]) == 0 or sz(mp[x]) == 0) {
			ans += max(sz(y), sz(mp[m-x]));
		} else {
			int a = sz(mp[x]), b = sz(mp[m - x]);
			if (a == b)
				ans++;
			else
				ans += 1 + sz(mp[x]) + sz(mp[m - x]) - (min(a, b) + min(a, b) + 1);
			done[x] = done[m - x] = 1;
		}
		// print(x, y, ans);
	}
	print(ans);
}
 
 
