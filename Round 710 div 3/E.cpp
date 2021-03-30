void solve() {
	int n, i, j;
	cin >> n;
	vi A(n+1);
	iota(all(A), 0);
	set<int> s1(1 + all(A)), s2(1+all(A));
	f1(i, n)
		cin >> A[i];
 
	f1(i, n) {
		if (A[i] != A[i-1])  
			cout << A[i] << ' ', s1.erase(A[i]);
		else {
			cout << *s1.begin() << ' ';
			s1.erase(s1.begin());
		}
	}
	cout << endl;
	f1(i, n) {
		if (A[i] != A[i-1])
			cout << A[i] << ' ', s2.erase(A[i]);
		else {
			auto it = prev(s2.lower_bound(A[i]));
			cout << *it << ' ';
			s2.erase(it);
		}
	}
cout << endl;
}	
