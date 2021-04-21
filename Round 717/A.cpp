#include<bits/stdc++.h>
using namespace std;

main() {
	int t;
	for (cin >> t; t--;) {
		int n, i, k;
		cin >> n >> k;
		vector<int> A(n);
		for(int& x : A) cin >> x;
		for (i = 0; i < n; i++) {
			int can = min(k, A[i]);
			A[n - 1] += can;
			A[i] -= can;
			k -= can;
			cout << A[i] << " \n"[i == n - 1];
		}
	}
}
