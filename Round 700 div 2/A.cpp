 
void solve() {
	string s;
	cin >> s;
	int i;
	f0(i, sz(s)) {
		if (i&1) {
			if (s[i] == 'z')
				s[i] = 'y';
			else s[i] = 'z';
		} else {
			if (s[i] == 'a')
				s[i] = 'b';
			else s[i] = 'a';
		}
	}
	print(s);
}
 
