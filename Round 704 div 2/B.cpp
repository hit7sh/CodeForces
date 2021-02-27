void solve() {
	int n, i, j;
	cin >> n;
	vi P(n);
	cin >> P;
	vector<pair<int, int>> A(n);
	f0(i, n) {
		A[i].F = P[i], A[i].S = i;
	}
	sort(rall(A));
 
	for (auto& [e, id] : A) {
		int x = id;
		if (id >= sz(P))
			continue;
		for (; id < sz(P); id++)
			cout << P[id] << ' ';
		P.erase(P.begin() + x, P.end());
	}
	cout << endl;
}
