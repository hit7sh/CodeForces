	// Author :: <Hitesh_Saini>
	#include<bits/stdc++.h>

	#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
	#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n"

	#define Yes(x) print((x) ? "Yes" : "No")
	#define tt 	int t; for (cin >> t; t--; )

	#define f0(i, n)  for (i = 0; i < (int)(n); i++)
	#define f1(i, n)  for (i = 1; i <=(int)(n); i++)

	#define cmax(x, y) x = max(x, y)
	#define cmin(x, y) x = min(x, y)

	#define all(x) x.begin(), x.end()
	



	using namespace std;

	using ll = long long;
	using vi = vector<int>;



	template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

	template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
	





	void solve() {
		int n, m, k, i, j;
		cin >> n;
		vi A(n);
		cin >> A;

		int mx = *max_element(all(A));
		vi dp(mx + 1), cnt(mx + 1);

		for (int& x:A)
			cnt[x]++;

		f1(i, mx) {
			dp[i] += cnt[i];
			for (j = i + i; j <= mx; j += i)
				cmax(dp[j], dp[i]);
		}
    
		print(n - *max_element(all(dp)));
	}









	int main() {
		
	    __speed() tt solve();

	    return 0;
	}
