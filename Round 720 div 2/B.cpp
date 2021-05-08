

vl primes;
vector<int64_t> segmentedSieve(int64_t L, int64_t R) { // R - L + 1 <= 1e7
    int64_t i, j;
    vector<int64_t> P;
    vector<bool> isPrime(R - L + 1, true);

    for(i = 2; i * i <= R; i++){
        int64_t j = max(i + i, ((L + i - 1) / i) * i);

        for(; j <= R; j += i)
            isPrime[j - L] = false;
    }

    for(i = L; i <= R; i++)
        if(i - 1 && isPrime[i-L])
            P.emplace_back(i);

    return P;
}

void solve() {
	int n, i;
	// n = random(1, 100000);
	cin >> n;
	vi A(n);
	cin >> A;
	// vi og = A;
	vector<vector<int>> ans;
	ll pp = -1, nn = sz(primes);
	f0(i, n - 1) {
		if (gcd(A[i], A[i + 1]) != 1) {
			pp = (pp + 1) % nn;
			ans.PB({i + 2, i + 1, min(A[i], A[i + 1]), (int)primes[pp]});
			A[i + 1] = min(A[i], A[i + 1]), A[i] = primes[pp];
		}
	}
	print(sz(ans));
	for (auto& x : ans)
		print(x);
}

signed main() { 
	cout << fixed << setprecision(12);
	primes = segmentedSieve(int(1e9 + 1), int(1e9 + 1e7));
	__speed() tt solve();
	 // int t, i; for (cin >> t, i = 1; i <= t; i++) cout << "Case #" << i << ": ", solve();
}
