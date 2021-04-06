bool chk(string s) {
	for (int  i = 0; i < sz(s)/2; i++)
		if (s[i] != s[sz(s) - 1 - i])
			return 0;
return 1;
}
 
void solve() {
	string s;
	cin >> s;
	bool ok = 1;
	int i = 0, j = sz(s) - 1, n = sz(s);
 
	if (count_if(all(s), [](char x) { return x == 'a';}) == n) {
		print("NO");
		return;
	}
	print("YES");
	if (!chk('a' + s))
		print('a' + s);
	else if (!chk(s + 'a'))
		print(s + 'a');
	else print(s[0] + "a" + s.substr(1));
	cout << endl;
}
