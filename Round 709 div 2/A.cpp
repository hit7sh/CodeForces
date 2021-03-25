void solve() {
	int a, b;
	cin >> a >> b;
	if (a > b)
		swap(a, b);
	print((b-1)*1LL*a + a);
}	
