 
void solve() {
	int n;
	cin >> n;
	vi A(n);
	cin >> A;
	int x = 0;
	mii mp;
	for (int& y : A)
		mp[y]++;
	for (auto& [y, z] : mp)
		if (z == 1)
			x = y;
	for (int i = 0; i < n; i++)
		if (A[i] == x) {
			print(i + 1);
			return ;
		}
}
