bool pal(string s) {
	for (int i = 0; i < sz(s); i++)
		if (s[i] != s[sz(s) - 1 - i])
			return 0;
		return 1;
}
 
 
void solve() {
	vi c(2);
	cin >> c;
	int c0 = c[0], c1 = c[1];
	string s;
	cin >> s;
	c[0] -= count_if(all(s), [](char x) {return x == '0';});
	c[1] -= count_if(all(s), [](char x) {return x == '1';});
	int i, n = sz(s);
	f0(i, n/2) {
		if ((s[i] == '?' && s[n - i - 1] != '?'))
			s[i] = s[n - i - 1], c[s[i]^48]--;
		else if (s[n - i - 1] == '?' && s[i] != '?')
			s[n - i - 1] = s[i], c[s[i]^48]--;
	}
	f0(i, n/2) {
		if (s[i] == '?') {
			if (c[0] >= c[1] && c[0] - 2 >= 0)
				s[i] = s[n - i - 1] = '0', c[0] -= 2;
			else if (c[1] - 2 >= 0)
				s[i] = s[n - i - 1] = '1', c[1] -= 2;
		}
	}
	if (n & 1 && s[n / 2] == '?')
		if (c[0] >= c[1] and c[0] - 1 >= 0)
			s[n/2] = '0', c[0]--;
		else if (c[1] - 1 >= 0) s[n/2] = '1', c[1]--;
		
	c[0] = count_if(all(s), [](char x) {return x == '0';});
	c[1] = count_if(all(s), [](char x) {return x == '1';});
	if (count_if(all(s), [](char x) {return x == '?';}) or !pal(s) or c[0] != c0 or c[1] != c1)
		cout << -1 << endl;
		else cout << s << endl;
}
 
