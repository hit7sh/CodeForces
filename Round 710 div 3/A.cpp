void solve() {
	ll n, m, x;
	cin >> n >> m >> x;
	ll tn = x%n;
	if (tn == 0)tn=n;
	ll tm = (x - tn)/n + 1;
	print((tn-1)*m+ tm);
}	
 
