void solve() {
	ll a, b;
	cin >> a >> b;
	if (b == 1) print("NO");
	else {
		print("YES");
		if (b == 2) b = 4;
		print(a, (b - 1) * a, a * b);
	}
}
