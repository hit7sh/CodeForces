int d = 0;
void fx(vi& A, int l, int r, int i) {
	auto mx = max_element(l+A.begin(), r+A.begin());
	int mxp = mx-A.begin();
	if (*mx == A[i])
		return;
	d++;
	if (mxp > i)
		fx(A, l, mxp, i);
	else
		fx(A, mxp+1, r, i);
}
 
 
void solve() {
	int n;
	cin >> n;
	vi A(n);
	cin >> A;
	int i;
	f0(i, n){
		d = 0;
		fx(A, 0, n, i);
		cout << d << ' ';
	}
	cout << endl;
}
 
