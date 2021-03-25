int solve(vector<int>& a, vector<int>& b) {
  int i = 0;
  int ret = 0;
 
  int same = 0;
  for (int j = 0; j < b.size(); ++j) if (binary_search(a.begin(), a.end(), b[j])) ++same;
 
  for (int j = 0; j < b.size(); ++j) {
    same -= (binary_search(all(a), b[j]));
    while (i < a.size() && a[i] <= b[j]) ++i;
    ret = max(ret, j - (int) (upper_bound(all(b), b[j] - i) - b.begin()) + 1 + same);
    // print(j, ret);
  }
  return ret;
}


void solve() {
	int n, m, i, j;
	cin >> n >> m;
	vi A1, B1, A2, B2;
	while (n--) {
		cin >> i;
		if (i > 0)
			A1.EB(i);
		else
			A2.EB(-i);
	}
	while (m--) {
		cin >> i;
		if (i > 0)
			B1.EB(i);
		else
			B2.EB(-i);
	}
	reverse(all(A2));
	reverse(all(B2));
	print(solve(A1, B1) + solve(A2, B2));
}	
