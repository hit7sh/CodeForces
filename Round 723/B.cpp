void solve() {
	int n;
	cin >> n;
	int md = 0;
	// 11a + 111b = n
	// 11a = n % 111
	// a = n * 11`
	ll a = (n % 111) * 101 % 111;
	Yes(n - 11 * a >= 0 && (n - 11 * a) % 111 == 0);
}
