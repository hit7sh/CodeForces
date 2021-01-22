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

using vvi = vector<vi>;
using vl = vector<ll>;

const int mod = 1e9+7, mxN = 2e5+5, INF = 0x3f3f3f3f;



template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

template <typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) { in >> p.F >> p.S; return in; }
template <typename T1, typename T2> ostream& operator<<(ostream& ot, pair<T1, T2>& p) { ot << p.F << ' ' << p.S; return ot; }

template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot; }





void solve() {
	int n, i;
	cin >> n;
	n *= 2;
	vi A(n);
  
	cin >> A;
	sort(all(A));

	auto possible = [&](int x) -> bool {
		multiset<int> M;
		vector<pair<int, int>> res;

		for (int& i:A)
			M.insert(i);

		while (!M.empty()) {
			int y = *M.rbegin();
			M.erase(M.find(y));
			if (y >= x)
				return false;
			int z = x-y;
			if (M.find(z) == M.end())
				return false;
			M.erase(M.find(z));
			res.emplace_back(y, z);
			x = y;
		}
		print("YES");
		print(res[0].F + res[0].S);
		print(res);
		return true;
	};

	f0(i, n-1) {
		if (possible(A[n-1] + A[i]))
			return;
	}
	print("NO");
}









int main() {

    __speed() tt solve();

    return 0;
}
