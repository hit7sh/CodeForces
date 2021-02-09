void solve() {
	int x, y;
	cin >> x >> y;
	if (x > y)
		swap(x, y);
	int ans = 2*x;
	y-=x;
	ans += y + max(0, y-1);
	print(ans);
}
 
