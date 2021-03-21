void solve() {
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	int w = min(k1, k2), b = n - max(k1, k2), B, W;
	w += (max(k1, k2) - min(k1, k2)) / 2;
	b += (max(k1, k2) - min(k1, k2)) / 2;
	cin >> W >> B;
	// print(w, b);
	Yes(w >= W && b >= B);
}
 
