
void solve() {
	int n, k, i;
	cin >> n >> k;
	if (k > (n - 1) / 2)
		print(-1);
	else {
		vi A(n);
		iota(all(A), 1);
		vi ans(n);
		for (i = 1; k && i < n; i += 2) {
			ans[i] = A.back();
			A.pop_back();
			k--;
		}
		while (sz(A)) {
			f0(i, n) {
				if (!ans[i]) {
					ans[i] = A.back();
					A.pop_back();
					break;
				}
			}
		}
		print(ans);
	}
}
