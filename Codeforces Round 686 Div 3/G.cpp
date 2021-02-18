void solve() {
	ll n, m, i, required, sum = 0;
	cin >> n >> m;
	vl A(n), pref_sum_max(n);
	f0(i, n) {
		cin >> A[i];
		sum += A[i];
		if (i==0)
			pref_sum_max[i] = sum;
		else
			pref_sum_max[i] = max(sum, pref_sum_max[i-1]);
	}

	while (m--) {
		cin >> required;
		if (required > pref_sum_max.back() && sum <= 0) {
			cout << "-1 ";
			continue;
		}
		ll cycles = 0, c = 0;
		if (required > pref_sum_max.back()) { // cycles exist
			cycles = (required - pref_sum_max.back() + sum - 1) / sum;
			c = cycles * n;
			required -= cycles * sum;
		}
		c += lower_bound(all(pref_sum_max), required) - pref_sum_max.begin();
		cout << c << ' ';
	}
	cout << endl;
}
