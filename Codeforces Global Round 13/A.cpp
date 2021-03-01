
void solve() {
	int n, q;
	cin >> n >> q;
	vi A(n);
	cin >> A;
	int oc = 0;
	for (int& x : A)
		oc += x == 1;
	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			if (A[x-1] == 0)
				oc++;
			else
				oc--;
			A[x-1] ^= 1;
		} else {
			if (x <= oc)
				print(1);
			else
				print(0);
		}
	}
}
 
