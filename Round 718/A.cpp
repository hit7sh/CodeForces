void solve() {
	ll n;
	cin >> n;
	ll ans = 0, pw = 1;
	if (n % 2050) print(-1);
	else {
		pw = 2050 * pow(10LL, 15);
		while (pw != 205) {
			ans += n / pw;
			n -= n / pw * pw;
			pw /= 10;
		}
		print(ans);
	}
}
