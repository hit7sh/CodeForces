void solve() {
	int n, i, j;
	cin >> n;
	string s;
	cin >> s;
	string a, b;
	// string os = s;
	int ones = count_if(all(s), [](char x) { return x == '1';});
	if (s.front() == '0' or s.back() == '0' or (ones & 1)) {
		print("NO");
		return;
	}
	print("YES");
	int oc = 0, f = 0;
	f0(i, n) {
		if (s[i] == '1') {
			if (oc < ones/2)
				a += '(', b +='(';
			else
				a += ')', b += ')';
			oc++;
		} else {
			a += "()"[f];
			b += ")("[f];
			f ^= 1;
		}
	}
	print(a, b);
}
 
