void solve() {
	int n;
	cin >> n;
	auto qry = [] (int l, int r) -> int {
		if (l == r) return -1;
		print('?', l, r);
		cin >> l;
		return l;
	};
	int L = 1, R = n, M, tsmaxi = qry(1, n);
	while (L < R) {
		M = (L + R) / 2;
		if ((tsmaxi <= M && qry(min(L, tsmaxi), M) != tsmaxi) or ((tsmaxi > M) && qry(M + 1, max(R, tsmaxi)) == tsmaxi))
			L = M + 1;
		else R = M;
	}
	print('!', L);
}	
 
