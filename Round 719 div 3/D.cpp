 
void solve() {
	int n,i ;
	cin >> n;
	vi A(n);
	cin >> A;
	ll ans = 0;
	f0(i, n) {
		A[i] -= i;
	}
	mii mp;
	for (int& x : A)
		mp[x]++;
	for (auto& [x, y] : mp) {
		ans += y * 1LL * (y - 1) / 2;
	}
	print(ans);
}
 
 
