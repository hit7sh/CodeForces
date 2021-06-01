void solve() {
	int n;
	cin >> n;
	vi A(n);
	cin >> A;
	ll sm = 0;
	multiset<int> st;
 
	for (int& x : A) {
		sm += x;
		st.insert(x);
 
		while (sm < 0) sm -= *st.begin(), st.erase(st.begin());
	}
	print(sz(st));
}
