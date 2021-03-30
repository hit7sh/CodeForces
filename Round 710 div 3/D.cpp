void solve() {
	int n;
	cin >> n;
	vi A(n);
	cin >> A;
	mii m;
	for (int x : A)
		m[x]++;
	int mf = 0;
	for (auto&[x, y] : m)
		cmax(mf, y);
	print(max(n&1, 2*mf - n));
 
}	
