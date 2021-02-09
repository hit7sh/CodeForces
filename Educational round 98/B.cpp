 
 
void solve() {
	int n;
	cin >> n;
	vi A(n);
	cin >> A;
	ll sm = accumulate(all(A), 0LL);
	ll mx = *max_element(all(A));
	if (n == 2) {
		print(0);
		return;
	}
	print(max(mx, (sm + n - 1 - 1)/(n-1))*(n-1) - sm );
}
 
