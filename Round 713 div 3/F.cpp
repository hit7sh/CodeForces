
void solve() {
	ll N, C;
	cin >> N >> C;
	vl A(N), B(N - 1);
	cin >> A >> B;
	ll ans = LINF, days = 0, earned = 0, i;
	f0(i, N) {
		if (earned >= C) cmin(ans, days);
		cmin(ans, days + (C - earned + A[i] - 1) / A[i]);

		if (B[i] > earned) {
			ll work_for = (B[i] - earned + A[i] - 1) / A[i];
			days += work_for;
			earned += work_for * A[i];
		}

		if (i < N - 1) {
			earned -= B[i]; // spend and move to next job...
			days++;	
		}
	}
	print(ans);
}
