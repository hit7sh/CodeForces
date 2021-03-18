 
void solve() {
	int n;
	cin >> n;
	vi A(n);
	cin >> A;
	vi f(101);
	for (int& x : A)
		f[x]++;
	for (int i = 0; i <=100; i++) {
		if (f[i])
			cout << i << ' ', f[i]--;
	}
	for (int i = 0; i <=100; i++) {
		while (f[i]--)
			cout << i << ' ';
	}
	cout << endl;
}
