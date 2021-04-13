void solve() {
	int n, k;
  cin >> n >> k;
  string s;
  for (int i = 0; i < k; i++){
    s += (char) ('a' + i);
    if (i > 0){
      s += (char) ('a' + i);
    }
  }
  set<pair<char, char>> vis;
  for (char x = 'a'; x < 'a' + k; x++)
  	vis.insert({x, x});
  for (char x = 'a'; x < 'a' + k - 1; x++)

  while (true) {
  	bool found = false;
  	for (char x = 'a' + k - 1; x >= 'a'; x--) {
  		if (!vis.count({s.back(), x})) {
  			vis.insert({s.back(), x});
  			s += x;
  			found = true;
  			break;
  		}
  	}
  	if (!found) break;
  }
  for (int i = 0; i < n; i++)
  	cout << s[i % sz(s)];
}
 
