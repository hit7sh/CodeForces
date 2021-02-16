 
void solve() {
	int n, i, j;
	cin >> n;
	vi A(n);
	cin >> A;
	vi B = A;
	sort(all(B));
	vi np;
	ll sm = 0, lnp = -1;
	f0(i, n-1) {
		sm += B[i];
		if (sm < B[i+1])
			lnp = i;
	}
	int rem = 0;
	print(n-lnp-1);
	f0(i, n)
		if (lnp == -1 or A[i] > B[lnp])
			cout << i+1 << ' ';
	cout << endl;
}
 
