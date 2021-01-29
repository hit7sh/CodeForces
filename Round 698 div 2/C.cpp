	// Author :: <Hitesh_Saini>
	#include<bits/stdc++.h>

	#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
	#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n"

	#define Yes(x) print((x) ? "Yes" : "No")
	#define tt 	int t; for (cin >> t; t--; )

	#define f0(i, n)  for (i = 0; i < (int)(n); i++)
	#define f1(i, n)  for (i = 1; i <=(int)(n); i++)


	#define all(x) x.begin(), x.end()

	#define EB emplace_back
	#define PB push_back


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
		ll i, j, n, k;

		cin >> n;
		n <<= 1;

		vl A(n);
		cin >> A;

		map<ll, ll> mp;

		for(auto&x:A)
			mp[x]++;

		vl d;
		for(auto&[v, f]:mp) {
			if (f!=2) {
				print("No");
				return;
			}
			d.EB(v);
		}
		reverse(all(d));

		ll cur = n, sum = 0;
		f0(i, n/2) {
			d[i] -= sum;
			if (d[i] <= 0 or d[i]%cur != 0) {
				print("No");
				return;
			}
			sum += 2*(d[i]/cur);
			cur -= 2;
		}
		print("Yes");
	}






	int main() {
		
	    __speed() tt solve();

	    return 0;
	}
