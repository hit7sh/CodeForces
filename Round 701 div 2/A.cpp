ll op(ll a, ll b) {
	ll o = 0;
	while (a) 
    a/=b, o++;
	return o;
}
 
 
void solve() {
	ll a, b, i;
	cin >> a >> b;

	ll ans = 0;
	if (b==1)
		ans++, b++;
 
	while (a) {
 
		ll b0 = op(a, b), b1 = op(a, b+1);
		if (b1 + 1 <= b0) {
			b++, ans++;
			continue;
		}
		else
			a /= b, ans++;
	}
	print(ans);
}
 
