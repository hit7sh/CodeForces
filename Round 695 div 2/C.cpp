void solve() {
	int a, b, c, d;
	cin >> a >> b >> c;
	vl sm(3), A(a), B(b), C(c);
	cin >> A >> B >> C;
	ll s1, s2, s3, t, m1, m2, m3;
	s1 = s2 = s3 = t = 0;
	m1 = m2 = m3 = INF;
	for (ll& x : A) s1 += x, cmin(m1, x);
	for (ll& x : B) s2 += x, cmin(m2, x);
	for (ll& x : C) s3 += x, cmin(m3, x);
	t = s1 + s2 + s3;
	print(t - 2 * min({s1, s2, s3, m1 + m2, m2 + m3, m3 + m1}));
}
 
