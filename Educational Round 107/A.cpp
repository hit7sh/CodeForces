 
void solve() {
	int n;
	cin >> n;
	vi A(n);
	cin >> A;
	vi cnt(4);
	for (int &x : A)
		cnt[x]++;
	cnt[1] += cnt[3];
	cout << cnt[1] << endl;
}
