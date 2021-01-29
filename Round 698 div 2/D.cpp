	// Author :: <Hitesh_Saini>
	#include<bits/stdc++.h>

	#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
	#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n"

	#define Yes(x) print((x) ? "Yes" : "No")
	#define tt 	int t; for (cin >> t; t--; )

	#define f0(i, n)  for (i = 0; i < (int)(n); i++)
	#define f1(i, n)  for (i = 1; i <=(int)(n); i++)




	using namespace std;
	using mii = map<int, int>;
	using pii = pair<int, int>;

	using ll = long long;
	using vi = vector<int>;

	using vvi = vector<vi>;
	using vl = vector<ll>;


	template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

	template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }







	void solve() {
		ll i, j, n, d, k;

		cin >> n >> k;
		vl A(n);
		cin >> A;

		k -= A[0];
		ll g = 0;
			
		f1(i, n-1)
			g = gcd(g, abs(A[i]-A[0]));

		Yes(k%g==0);

	}






	int main() {
		
	    __speed() tt solve();

	    return 0;
	}
