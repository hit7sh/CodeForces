ll prime[] = {0, 2, 11, 101, 1009, 10007, 100003, 1000003, 10000019, (ll)1e8+7};
int countDigit(long long n) {
  return floor(log10(n) + 1);
}
void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll A, B;
	A = B = prime[c];
	while (countDigit(A) < a) A *= 2;
	while (countDigit(B) < b) B *= 3;
	print(A, B);
	assert(ll(log10(gcd(A, B)) + 1) == c);
}
