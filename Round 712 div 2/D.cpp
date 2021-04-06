void solve() {
	int n, i, j, a, b;
	cin >> n;
	vector<pair<int, int>> black, white;
	f1(i, n) f1(j, n) if ((i + j) & 1) black.EB(i, j); else white.EB(i, j);
	while (sz(black) && sz(white)) {
		cin  >> a;
		if (a == 2 or a == 3)
			print(1, black.back()), black.pop_back();
		else
			print(2, white.back()), white.pop_back();
	}
	while (sz(black))
		cin >> a, print(a == 2 or a == 3 ? 1 : 3, black.back()), black.pop_back();
	while (sz(white))
		cin >> a, print(a == 1 or a == 3 ? 2 : 3, white.back()), white.pop_back();
}
