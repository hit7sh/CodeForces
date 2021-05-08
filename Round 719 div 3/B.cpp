void solve() {
	int n, i;
	string s;
	cin >> s;
	n = sz(s);
	int ans = 9 * (n - 1);
	int nm = stoi(s), to = stoi(string(n, s[0]));
	if (nm >= to) ans++;
	ans += s[0] - '0' - 1;
	print(ans);
}
 
