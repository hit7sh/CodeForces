void solve() {
	int n;
	cin >> n;
	int k, f, ls, L = 1, R = n, M, md, md1;
	while (L < R) {
		M = (L + R) / 2;
		print('?', M);
		cin >> md;
		print('?', M+1);
		cin >> md1;
		if (md < md1)
			R = M;
		else
			L = M + 1;
	}
	print('!', L);
}
 
