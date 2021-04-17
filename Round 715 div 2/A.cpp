void solve() {
	int n;
	cin >> n;
	vi A(n);
	cin >> A;
	sort(all(A), [](int a, int b) { return ~a&1 && b&1;});
	print(A);
}
 
