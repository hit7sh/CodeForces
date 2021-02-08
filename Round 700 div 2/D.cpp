 
void solve() {
	int n, i, j;
	cin >> n;
	vi A(n);
	cin >> A;
	int ans = n, s1, s2;
	s1 = s2 = -1;

	f0(i, n) {
		int x = A[i];
		if (s1 != x && s2 != x) {
			if (i + 1 < n && A[i+1] == s1)
				s1 = x;
			else 
				s2 = x;
		} else if (s1 != x && s2 == x)
			s1 = x;
		else if (s2 != x && s1 == x)
			s2 = x;
		else ans--;
	}
	
	
	print(ans);
}
