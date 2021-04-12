 
 
void solve() {
	int i, j, k, n;
	cin >> n;
	vl B(n + 2);
	cin >> B;
	sort(all(B));
	ll sm = accumulate(all(B) - 2, 0LL);
	if (sm == B[n]) {
		B.pop_back(), B.pop_back(), print(B);
		return;
	}
	sm += B[n];
	f0(i, n + 1) {
		if (sm - B[i] == B.back()) {
			f0(j, n + 1)
				if (i == j) continue;
				else cout << B[j] << ' ';
			cout << endl;
			return;
		}
	}
	sm = accumulate(all(B) - 2, 0LL);
	// if (binary_search(all()))
	cout << -1 << endl;
}
 
