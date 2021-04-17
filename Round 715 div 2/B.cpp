
void solve() {
	int n, i, j;
	cin >> n;
	string s;
	cin >> s;
	vi pref(n + 1), M;
	set<int> pt, pm;
	f0(i, n) {
		if (s[i] == 'T')
			pt.insert(i);
		else pm.insert(i), M.EB(i);
	}
	if (sz(pm) * 2 != sz(pt)) {Yes(0); return;}
	int ct = 0, cm = 0, ok = 1;
	f0(i, n) {
		if (s[i] == 'T') ct++;
		else cm++;
		if (ct < cm) ok = 0;
	}
	reverse(all(s));
	ct = cm = 0;
	f0(i, n) {
		if (s[i] == 'T') ct++;
		else cm++;
		if (ct < cm) ok = 0;
	}
	Yes(ok);
 
}
