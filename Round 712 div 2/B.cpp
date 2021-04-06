void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int oc = 0, zc = 0;
	int i, j, c = 0;
	f0(i, n) {
		zc += (a[i] == '0');
		oc += (a[i] == '1');
	}
 
	vi inc(n + 1);
	for (i = n - 1; ~i; --i) {
		if (oc == zc) {
			if ((a[i] ^ (c & 1)) != b[i])
				c++, inc[i + 1] = -1, swap(zc, oc);
		}
		// print(zc, oc, c);
		zc -= a[i] == '0';
		oc -= a[i] == '1';
	}
	inc[0] = c;
	f1(i, n)
		inc[i] += inc[i - 1];
	f0(i, n)
		a[i] ^= inc[i] & 1;
	Yes(a == b);
}
 
