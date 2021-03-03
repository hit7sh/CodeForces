bool chk(string s) {
	stack<char> stk;
	for (char x : s) {
		if (!stk.empty() && stk.top() == '(' && x == ')')
			stk.pop();
		else
			stk.push(x);
	}
	return stk.empty();
}
 
void solve() {
	string v = "()";
	string s;
	cin >> s;
	bool ok = 0;
	for (int i = 0; i < (1<<3); i++) {
		map<char, char> mp;
		mp['A'] = v[i & (1<<0)]; 
		mp['B'] = v[!!(i & (1<<1))];
		mp['C'] = v[!!(i & (1<<2))];
		
		string tp;
		for (char x : s)
			tp += mp[x];
		if (ok = chk(tp))
			break;
	}
	Yes(ok);
}
 
