// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n";
#define tt int t; for (cin>>t; t--; )

#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define f1(i, n)  for (i = 1; i<= (int)(n); i++)

#define cmax(x, y) x = max(x, y);
#define cmin(x, y) x = min(x, y);

using namespace std;
using vi = vector<int>;


template<typename... T> void print(T... args) { ((cout << args << " "), ...); cout << endl; }
template<typename T> istream& operator>>(istream& in, vector<T> &a) { for (auto&x:a)in>>x; return in; }








void solve() {
	int n, i, j;
	cin >> n;
	vi A(n);
	cin >> A;
	int ans = 0, c = 0;
	auto chk = [&](int i) {
		if (i < n-1 && i > 0) 
			return (A[i] > A[i - 1] && A[i] > A[i + 1]) || (A[i] < A[i - 1] && A[i] < A[i + 1]);
		return false;
	};
	f1(i, n - 2)
		c += chk(i);
	ans = c;
	
	f1(i, n - 2) {
		int tc = c;

		tc -= chk(i - 1) + chk(i) + chk(i + 1);

		int original = A[i];
		A[i] = A[i - 1];
		cmin(ans, tc + chk(i - 1) + chk(i) + chk(i + 1));
		A[i] = A[i + 1];
		cmin(ans, tc + chk(i - 1) + chk(i) + chk(i + 1));
		A[i] = original;
	}

	print(ans);
}


signed main() {
    __speed() tt solve();
    return 0;
}
