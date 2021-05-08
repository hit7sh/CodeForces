 
void solve() {
	int n;
	string s;
	cin >> n >> s;
	vi freq(26);
	for (char& x : s) freq[x - 'A']++;
	freq[s[0] - 'A']--;
  bool ok = 1;
  for (int i = 1; i < n; ++i)
  {
	  if (s[i] != s[i - 1] && freq[s[i - 1] - 'A'] > 0) {ok  = 0; }
	  freq[s[i] - 'A']--;
  }
		Yes(ok);
}
 
