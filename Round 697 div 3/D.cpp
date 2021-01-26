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


using namespace std;

using ll = long long;
using vi = vector<int>;


const int mod = 1e9+7, mxN = 2e5+5, INF = 0x3f3f3f3f;



template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

template <typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) { in >> p.F >> p.S; return in; }
template <typename T1, typename T2> ostream& operator<<(ostream& ot, pair<T1, T2>& p) { ot << p.F << ' ' << p.S; return ot; }

template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot; }






void solve() {
	int n, m, k, i, j;
	cin >> n >> m;
	vi A(n), B(n);
	cin >> A >> B;

	vi ones, twos;

	f0(i, n)
		(B[i] - 1 ? twos : ones).EB(A[i]);

	sort(rall(ones));
	sort(rall(twos));

	int l1 = sz(ones), l2 = sz(twos);
	ll os = 0, ts = accumulate(all(twos), 0LL), ans = INF;

	for (i = 0; i <= l1; i++) {
		while (l2 > 0 && os + ts - twos[l2-1] >= m)
			l2--, ts -= twos[l2];

		if (os + ts >= m)
			cmin(ans, 2LL*l2+i);

		if (i < l1)
			os += ones[i];
	}
	ans = ans == INF ? -1 : ans;
	print(ans);
}









int main() {

   tt solve();

    return 0;
}
