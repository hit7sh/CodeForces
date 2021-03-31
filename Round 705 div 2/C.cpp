bool valid(vi f, int k) {
	for (int& x : f)
		if (x % k)
			return false;
	return true;
}
 
 
 
void solve() {
	int n, k, i, j, rem;
	string s;
	cin >> n >> k >> s;
	vi f(26);
	for (char& x : s)
		f[x - 'a']++;
	if (n % k) {
		print(-1);
		return;
	}
	if (valid(f, k)) {
		print(s);
		return;
	}
 
	for (i = n-1; ~i; --i) {
		f[s[i] - 'a']--;
		for (j = s[i] - 'a' + 1; j < 26; j++) {
			f[j]++;
			rem = n - 1 - i;
			for (int z = 0; z < 26; z++) {
				int need = k - f[z] % k;
				if (need == k) continue;
				rem -= need;
			}
			// print(j, i, rem);
			if (rem >= 0) {
				assert(rem % k == 0);
				s[i] = j + 'a';
				int pos = i + 1;
				for (int z = 0;	z < rem; z++)
					s[pos++] = 'a';
				for (int z = 0; z < 26; z++) {
					int need = k - f[z] % k;
					if (need == k) continue;
					for (int l = 0; l < need; l++)
						s[pos++] = 'a' + z;
				}
				print(s);
				return;
			}
			f[j]--;
		}
		// print(f);
	}
		print(-1);
 
}
