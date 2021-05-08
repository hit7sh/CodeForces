 
void solve() {
	int n, i, j;
	cin >> n;
	vvi A(n, vi(n));
	int l = 0, r = n * n + 1;
	f0(i, n) f0(j, n) if ((i + j)&1^1) A[i][j] = --r;
	f0(i, n) f0(j, n) if ((i + j) & 1) A[i][j] = --r;
 
	bool ok = 1;
	f0(i, n) f0(j, n) {
		for (auto& [a, b] : DD) {
			int x = i + a, y = j + b;
			if (x < n && y < n && ~x && ~y) {
				ok &= abs(A[i][j] - A[x][y]) != 1;
			}
		}
	}
	if (ok) {
		for (auto& x : A)
			print(x);
	} else print(-1);
}
 
 
