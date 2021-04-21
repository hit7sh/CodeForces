void solve() {
	int n, x = 0;
	cin >> n;
	vi A(n);
	cin >> A;
	for (int& y : A) x ^= y;
	if (x == 0)
		print("Yes");
	else {
		int c = 0, i, y = 0;
		f0(i, n) {
			y ^= A[i];
			if (y == x)
				y = 0, c++;
		}
		if (y == x) c++;
		Yes(c > 1);
	}
}
 
