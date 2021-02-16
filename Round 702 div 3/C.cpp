vl pc;
void init() {
	for (ll i = 1; 1LL*i*i*i <= 1e12; i++)
		pc.EB(i*i*i);
}
 
 
 
void solve() {
	ll n;
	cin >> n;
 
	for (ll i = 1; i*i*i < n; i++) {
		if (binary_search(all(pc), n - i*i*i)) {
			print("Yes");
			return;
		}
	}
	print("No");
}
 
int main() {
	init();
	__speed() tt solve();
								
}
