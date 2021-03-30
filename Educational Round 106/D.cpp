vl V(int(2e7+1));



void solve() {
	ll c, d, x;
	cin >> c >> d >> x;

	ll ans = 0;
	for (ll i = 1; i*i <= x; i++) {
		if (x % i == 0) {
			if ((i + d) % c == 0) 
				ans += 1LL << V[(x / i + d) / c];
			if (i * i != x) 
				if ((x / i + d) % c == 0)
					ans += 1LL << V[(i + d) / c];
		}
	}
	print(ans);
}

 
	

signed main() {
	__speed();

	for (int i = 2; i <= 2e7; i++)
		if (!V[i])
			for (int j = i; j <= 2e7; j+=i)
				V[j]++;                        // number of unique prime factors V[j]

	tt solve();
}
