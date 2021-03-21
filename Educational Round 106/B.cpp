 
void solve() {
	string s;
	cin >> s;
	int l = sz(s);
	while (--l >= 0)
		if (s[l] == '0')
			break;
	l++;
	int n = -1;
	while (++n < sz(s))
		if (s[n] == '1')
			break;
	if (l == 0 or n == sz(s)) {
		Yes(1);
		return;
	}
	int L = n, R = l - 1;
	while (L + 1 < sz(s)) {
		if (s[L] == '1' && s[L+1] == '1')
			break;
		L++;
	}
	while (R - 1 >= 0) {
			if (s[R] == '0' && s[R - 1] == '0')
				break;
			R--;
	}
	string s1 = s;
	sort(all(s));
	bool al = s1 == s;
	// print(L,  R);
	Yes(R<=L or al);
}
 
