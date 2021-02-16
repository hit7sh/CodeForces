void solve() {
	int n, i;
	cin >> n;
	vi A(n);
	cin >> A;
	int c0=0, c1=0, c2=0;
	for (int& x : A) {
		if (x%3==0)
			c0++;
		else if (x%3==1)
			c1++;
		else
			c2++;
	}
	
	int tm = (c0+c1+c2)/3;
	int c = (c0>tm) + (c1 > tm) + (c2 > tm);
	ll ans = 0;
	if (c==2) {
		if (c0>tm && c1>tm) {
		ans = c0-tm;
		c1 += c0-tm;
		ans += abs(c1-tm);
		} else if (c1>tm && c2>tm) {
			ans = c1-tm;
		c2 += c1-tm;
		ans += abs(c2-tm);
		} else {
			ans = c2 - tm;
		c0 += c2 - tm;
		ans += abs(c0-tm);
		}
		print(ans);
		return;
	}
	if (c0>tm) {
		ans = c0-tm;
		c1 += c0-tm;
		ans += abs(c1-tm);
	} else if (c1>tm) {
		ans = c1-tm;
		c2 += c1-tm;
		ans += abs(c2-tm);
	} else {
		ans = c2 - tm;
		c0 += c2 - tm;
		ans += abs(c0-tm);
	}
	print(ans);
}
