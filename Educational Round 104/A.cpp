void solve() {	
	int n;
	cin >> n;
	vi A(n);
	cin >> A;
	int mn = *min_element(all(A)), ans = 0;
	for (int x : A)
		ans += x>mn;
	print(ans);
}
