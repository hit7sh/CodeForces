void solve() {
	int n, k;
	cin >> n >> k;
	if (n&1)
		print(n/2, n/2, n - n/2 - n/2);
	else if (n/2 & 1)
		print(2, (n-2)/2, (n-2)/2);
	else 
		print(n/2, n/4, n/4);
 
}
