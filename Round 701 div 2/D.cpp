void solve() {
	int n, m, L = 1, i, j;
	cin >> n >> m;
	for (i = 2; i <= 16; i++)
		L = lcm(L, i);
	vvi A(n, vi(m));
	cin >> A;
	vvi ans(n, vi(m, L));
	f0(i, n)f0(j, m)if ((i+j)&1) ans[i][j] += A[i][j]*A[i][j]*A[i][j]*A[i][j];
	print(ans);
}
