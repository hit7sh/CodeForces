 
void solve() {
	int n;
	cin >> n;
	int i, x;
	map<int, int64_t> cnt;
	int64_t ans = 0;
	for (i = 0; i < n; i++) {
		cin >> x;
		ans += cnt[x] * (n - i);
		cnt[x] += i + 1;
	}
	print(ans);
}
