

void solve() {
	int N, L, R, K, S;
	cin >> N >> L >> R >> S;

	K = R - L + 1;
	if (S < K * (K + 1) / 2 or S > N * (N + 1) / 2 - (N - K) * (N - K + 1) / 2)
		print(-1);
	else {
		vi used(N + 1), P(N + 1);
		for (int i = N; i; i--) {
			S -= i;
			K--;
			if (S <	K * (K + 1) / 2)
				S += i, K++; // dont include i
			else
				used[i] = 1, P[L + K] = i; // include i
		}
		int id = 1;
		for (int i = 1; i <= N; i++) {
			if (i >= L && i <= R) cout << P[i] << ' '; // if in range print P[i]
			else {
				while (used[id]) id++;
				cout << id++ << ' ';
			}
		}
		cout << endl;
	}
}
