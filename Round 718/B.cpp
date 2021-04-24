void solve() {
	int n, m, r, i, j;
	cin >> n >> m; r = m;
	vvi B(n, vi(m)), ans(n, vi(m, -1));
 
	cin >> B;
	vector<array<int, 3>> al;
	f0(i, n) f0(j, m) al.push_back({B[i][j], i, j});
	sort(all(al));
 
	f0(j, m) {
		i = al[j][1];
		ans[i][j] = al[j][0];
	}
 
	for (int id = m; id < n * m; id++) {
		i = al[id][1];
		f0(j, m) {
			if (ans[i][j] == -1) {
				ans[i][j] = al[id][0];
				break;
			}
		}
	}
	for (auto& x : ans) print(x);
}
