void solve() {
	int n, i, j;
	cin >> n;
	vi A(n);
	cin >> A;
	mii freq;
	vi cnt(32);
	f0(i, 32)
		for (int& x : A)
			cnt[i] += (x >> i) & 1;
	for (int& x : A)
		freq[x]++;
	ll ans = 0;
	for (auto& [num, f] : freq) {
		if (f > 1) {
			f0(i, 32) {
				if (num & (1 << i))
					cnt[i] -= 2;
			}	
			int an = 0;
			f0(i, 32) {
				if (cnt[i] == n - 2)
					an |= 1 << i;
			}
			an &= num;
			if (an == num) ans = add(ans, mul(f*1LL*(f - 1), fact[n - 2]));
			f0(i, 32) {
				if (num & (1 << i))
					cnt[i] += 2;
			}
		}
	}
	print(ans);
}
 
