ll sm(ll n) {
	ll s = 0;
	do s += n%10; while (n/=10);
	return s;
}
 
 
void solve() {
	ll n;
	cin>> n;
	ll g = gcd(n, sm(n));
	while (g == 1) {
		n++;
		g = gcd(n, sm(n));
	}
	print(n);
}
