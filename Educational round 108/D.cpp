void solve() {
	int n;
	cin >> n;
	vl A(n), B(n);
	cin >> A >> B;
	vl pref(n), suf(n);
	pref[0] = A[0] * B[0];
	suf[n - 1] = A.back() * B.back();
	int i, j;
	f1(i, n - 1) {
		pref[i] = A[i] * B[i] + pref[i - 1];
	}
  
	for (i = n - 2; i >= 0; i--) {
		suf[i] = A[i] * B[i] + suf[i + 1];
	}
 
	int k, l;
	ll cur = 0, ans = pref.back();
	for (k = 1; k + 1 < n; k++) {
		cur = A[k] * B[k];
		for (i = k - 1, j = k + 1; i >= 0 && j < n; i--, j++) {
			cur += A[i] * B[j] + A[j] * B[i];
			cmax(ans, (i? pref[i - 1] : 0) + cur + (j + 1 < n ? suf[j + 1] : 0));
		}
	}
	for (k = 0; k + 1 < n; k++) {
		cur = 0;
		for (i = k, j = k + 1; i >= 0 && j < n; i--, j++) {
			cur += A[i] * B[j] + A[j] * B[i];
			cmax(ans, (i? pref[i - 1] : 0) + cur + (j + 1 < n ? suf[j + 1] : 0));
		}
	}
	print(ans);
}	 
 
