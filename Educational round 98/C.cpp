 
void solve() {
	string s;
	cin >> s;
	map<char, int> mp;
	int ans = 0;
	map<char, char> con;
	con[']'] = '[';
	con[')'] = '(';
	for (char &x : s) {
		if (x == '[' or x == '(')
			mp[x]++;
		else if (mp[con[x]] > 0)
			ans++, mp[con[x]]--;
	}
	print(ans);
}
 
