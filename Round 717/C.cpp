#include<bits/stdc++.h>
using namespace std;

main() {
	int n, i, mn = 30, sum = 0, ans = 0;
	cin >> n;
	vector<int> A(n);
	for (int& x : A) cin >> x, sum += x;
	vector<int> dp(sum + 1);
	dp[0] = 1;
	
	for (int& x : A)
		for (i = sum - x; i >= 0; i--)
			if (dp[i]) dp[i + x] = 1;

	if (sum & 1 or dp[sum/2] == 0) {
		cout << 0;
	} else {
		for(i = 0; i < n; i++)
			if (mn > __builtin_ctz(A[i]))
				mn = __builtin_ctz(A[i]), ans = i + 1;
		cout << 1 << endl << ans;
	}
}
