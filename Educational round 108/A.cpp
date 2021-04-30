void solve() {
	ll r, b, d;
	cin >> r >> b >> d;
	if (b > r) swap(r, b);
	r -= b;
	Yes((r + b - 1) / b <= d);
}	
