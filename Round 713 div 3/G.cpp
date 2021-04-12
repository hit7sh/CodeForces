ll sd[mxN];
ll ans[mxN];
 
void solve() {
	ll c;
	cin >> c;
 
	print(ans[c] ? ans[c] : -1);
}
 
void pre() {
	int i, j;
	for (i = 1; i < mxN; i++) 
		for (j = i; j < mxN; j += i)
			sd[j] += i;
	for (i = 1; i < mxN; i++)
		if (sd[i] < mxN && !ans[sd[i]])
			ans[sd[i]] = i;
 
}
