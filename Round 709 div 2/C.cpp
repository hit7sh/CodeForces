 
void solve() {	
	int n, m, i, j, k;
	cin >> n >> m;
	vvi A(m);
	f0(i, m) {
		cin >> k;
		vi t(k+1);
		t[0] = i;
		f1(j, k)
			cin >> t[j];
		A[i] = t;
	}
	sort(all(A), [](vi& A, vi& B){return sz(A) < sz(B);});
	vi ans(m);
	// for (auto x : A)
	// 	print(x);
	vi freq(n+1);
	f0(i, m) {
		bool found = 0;
		f1(j, sz(A[i]) - 1) {
			if (freq[A[i][j]] < (m+1)/2) {
				found = 1;
				ans[A[i][0]] = A[i][j];
				freq[A[i][j]]++;
				break;
			} 
		}
		if (!found) {
			print("NO");
			return;
		}
	}
	print("YES");
	print(ans);
}
 
 
