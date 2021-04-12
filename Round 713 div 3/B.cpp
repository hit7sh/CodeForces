void solve() {
	int n;
	cin >> n;
	vector<string> s(n);
	cin >> s;
	vector<pii> pos;
	int i, j;
	f0(i, n)
		f0(j, n)
			if (s[i][j] == '*')
				pos.EB(i, j);
	if (pos[0].F == pos[1].F)
		s[(pos[0].F + 1) % n][pos[0].S] = s[(pos[1].F + 1) % n][pos[1].S] = '*';
	else if (pos[0].S == pos[1].S)
		s[pos[0].F][(pos[0].S + 1) % n] = s[pos[1].F][(pos[1].S + 1) % n] = '*';
	else s[pos[0].F][pos[1].S] = s[pos[1].F][pos[0].S] = '*';
 
	f0(i, n) {
		f0(j, n)
			cout << s[i][j];
		cout << endl;
	}
	// cout << endl;
}
 
