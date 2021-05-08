void solve() {
	int n;
	cin >> n;
	function<int(int, int, int, int)> query = [](int t, int i, int j, int x) {
		cout << "? " << t << ' ' << i << ' ' << j << ' ' << x << endl;
		cin >> x;
		return x; 
	};
 
	int one = -1, i;
	vi ans(n + 1);
 
	for (i = 2; i <= n; i+= 2) {
		int q = query(2, i - 1, i, 1);
		if (q == 1) {
			one = i - 1;
			break;
		} else if (q == 2 && query(2, i, i - 1, 1) == 1) {
			one = i;
			break;
		}
	}
 
	if (one == -1) one = n;
	ans[one] = 1;
 
	f1(i, n) if (i != one) ans[i] = query(1, one, i, n - 1);
 
	ans.erase(ans.begin());
	cout << '!' << ' ';
	print(ans);
}
