void solve() {
	int n;
	cin >> n;
	vi A(n);
	cin >> A;
	Yes(count_if(all(A), [](int x) { int t = sqrt(x); return t*t == x;}) != n);
}
 
