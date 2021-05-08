void solve() {
	ll n, m, w, i, j;
	cin >> n >> m >> w;
	vector<vl> A(n, vl(m));
	cin >> A;
	
	vector<vl> src(n, vl(m, LINF)), dest(n, vl(m, LINF));
 
	queue<pii> q;
	q.push({0, 0});
	src[0][0] = 0;
	
	function<bool(int, int)> valid = [&](int i, int j) {
		return i>=0&&i<n&&j<m&&j>=0&&~A[i][j];
	};
	while (sz(q)) {
		pii f = q.front(); q.pop();
		for (auto& [x, y] : DD) {
			int xx = x + f.F, yy = y + f.S;
			if(!valid(xx, yy)) continue;
			if (src[xx][yy] <= 1 + src[f.F][f.S]) continue;
			src[xx][yy] = 1 + src[f.F][f.S];
			q.push({xx, yy});
		}
	}
	ll ans = LINF;
	if (src.back().back() != LINF) cmin(ans, src.back().back()*w); // without portal
 
	q.push({n - 1, m - 1});
	dest[n - 1][m - 1] = 0;
	while (sz(q)) {
		pii f = q.front(); q.pop();
		for (auto& [x, y] : DD) {
			int xx = x + f.F, yy = y + f.S;
			if (!valid(xx, yy)) continue;
			if (dest[xx][yy] <= 1 + dest[f.F][f.S]) continue;
			dest[xx][yy] = 1 + dest[f.F][f.S];
			q.push({xx, yy});
			
		}
	}
 
	ll minp1 = LINF, x1, y1;
	ll minp2 = LINF, x2, y2;
	x1 = y1 = x2 = y2 = 0;
	// for (auto& x : dest) print(x);
	f0(i, n) f0(j, m) {
		if (A[i][j] > 0 && src[i][j] != LINF)
			cmin(minp1, A[i][j] + src[i][j] * w);
	}
 
	f0(i, n) f0(j, m) {
		if (A[i][j] > 0 && dest[i][j] != LINF)
			cmin(minp2, A[i][j] + w*dest[i][j]);
	}
	cmin(ans, minp1 + minp2);
	bool bad = ans >= LINF;
 
	if (bad) print(-1);
	else print(ans);
}
 
 
