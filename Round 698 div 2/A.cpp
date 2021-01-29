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
	#define rall(x) x.rbegin(), x.rend()
	#define sz(x) (int)(x.size())

	#define EB emplace_back
	#define PB push_back

	#define endl "\n"
	#define S second
	#define F first



	using namespace std;
	using mii = map<int, int>;
	using pii = pair<int, int>;

	using ll = long long;
	using vi = vector<int>;



	template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

	template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }





void solve() {
	int n, m, k, i, j;
	cin >> n;
	vi A(n);
	cin >> A;
	int ans = 0;
	
	while(1) {
		stack<int> s;
		s.push(-1);
		f0(i, n)
			if (A[i] != -1 && A[i] > s.top())
				s.push(A[i]), A[i] = -1;
		if (sz(s) != 1)
			ans++;
		else {
			ans += sz(s)-1;
			break;
		}
	}

	print(ans);
}






	int main() {

	    __speed() tt solve();

	    return 0;
	}
