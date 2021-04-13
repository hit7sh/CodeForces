#include<bits/stdc++.h>
const int mxN = 3e5+5, M = 998244353;
int64_t dp[mxN], p2[mxN], i, j, n, m, cur, tot, R[mxN], C[mxN], ans;
main() {
	p2[0] = dp[2] = 1;
	p2[1] = 2;
	for (i = 2; i < mxN; i++)
		p2[i] = p2[i - 1] * 2 % M, dp[i + 1] = (dp[i] + 2 * dp[i - 1] + p2[i - 1]) % M;
	std::cin >> n >> m;
	int A[n + 1][m + 1];
	memset(A, 0, sizeof(A));
	char c;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) 
			std::cin >> c, A[i][j] = c == 'o', tot += A[i][j];
 
	for (i = 0; i <= n; i++)
		for (j = 0; j<= m; j++) 
			if (A[i][j]) cur++;
			else ans = (ans + dp[cur] * p2[tot - cur] % M) % M, cur = 0;
 
	for (i = 0; i <= m; i++)
		for (j = 0; j<= n; j++) 
			if (A[j][i]) cur++;
			else ans = (ans + dp[cur] * p2[tot - cur] % M) % M, cur = 0;
	std::cout << ans;
}
