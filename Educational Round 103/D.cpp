// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "(" << __LINE__ << ": "<< #x << " = " << x << ")\n"
 
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
 
using ll = int64_t;
using vi = vector<int>;
 
using vvi = vector<vi>;
using vl = vector<ll>;
 
const int mod = 1e9+7, mxN = 5e5+5, INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
 
 
template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }
 
template <typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) { in >> p.F >> p.S; return in; }
template <typename T1, typename T2> ostream& operator<<(ostream& ot, pair<T1, T2>& p) { ot << p.F << ' ' << p.S; return ot; }
 
template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot; }
 

 

class dsu{
public:
	vector<int>p, siz;
	int n;
	dsu(int _n):n(_n) {
		p.resize(n+1);
		siz.resize(n+1, 1);
		iota(p.begin(), p.end(), 0);
	}

	inline int get(int x) {
		return (x==p[x]?x:(p[x]=get(p[x])));
	}

	inline bool unite(int x, int y) {
		x=get(x);
		y=get(y);

		if (x == y)
			return false;

		if (siz[x] >= siz[y])
			swap(x, y);

		siz[y] += siz[x];
		p[x] = y;
		return true;

	}
};

 
void solve() {
	int n, i;
	string s;
	cin >> n >> s;
	dsu du(2*n+5);
	f0(i, n) {
		if (s[i] == 'L') {
			du.unite(i+1, i+n+1);
		} else {
			du.unite(i, i+1+n+1);
		}
	}
	for (i = 0; i <= n; i++) {
		print(du.siz[du.get(i)]);
	}
}
 





int main() {
			#ifndef ONLINE_JUDGE
								freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
							#endif


	__speed() tt solve();
}
