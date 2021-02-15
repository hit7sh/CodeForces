void solve() {
	int n, k;
	cin >> n >> k;k--;
	if (n&1^1) {
		print(k%n+1);
	} else {
		ll cr = (k)/(n/2) + k;
		print(cr%n+1);
	}
}
