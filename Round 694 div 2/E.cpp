// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "(" << __LINE__ << ": "<< #x << " = " << x << ")\n"
 
#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )
 
#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define f1(i, n)  for (i = 1; i <=(int)(n); i++)
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x.size())
 
#define EB emplace_back
#define PB push_back

#define LB lower_bound
#define UB upper_bound

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
 
const pair<int, int> DD[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int mod = 1e9 + 7, mxN = 1e5 + 5, INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
 

template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

template <typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) { in >> p.F >> p.S; return in; }
template <typename T1, typename T2> ostream& operator<<(ostream& ot, pair<T1, T2>& p) { ot << p.F << ' ' << p.S; return ot; }

template <typename T1, typename T2> bool cmax(T1& a, T2 b) { if (b > a) { a = b; return true;} return false; }
template <typename T1, typename T2> bool cmin(T1& a, T2 b) { if (b < a) { a = b; return true;} return false; }

template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot; }


const int N = 1000001;
int lp[N+1];
vector<int> pr;
void init() {
for (int i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
}
}

void solve() {
	int n;
	cin >> n;
	vi A(n);
	cin >> A;
	map<int, int> cnt;
	vi form(n);

	for (int i = 0; i < n; i++) {
		int x = A[i];
		mii pf;
		while (x > 1) {
			pf[lp[x]]++;
			x /= lp[x];
		}
		int f = 1;
		for (auto& [pr, pw] : pf) {
			if (pw & 1)
				f *= pr;
		}
		form[i] = f;
		cnt[form[i]]++;
	}

	ll ans0 = 0, ans1 = 0, ans2 = 0;

	for (auto &[f, p] : cnt) {
		// print(f, p);
		cmax(ans0, p);
		if (f == 1 or ~p & 1)
			ans2 += p;
		else cmax(ans1, p);
	}
	cmax(ans1, ans2);
	int q;
	ll t;
	for (cin >> q; q; q--) {
		cin >> t;
		if (t == 0) print(ans0);
		else print(ans1);
	}
}

	



signed main() { init();
	 __speed() tt solve();
	 // int t, i; for (cin >> t, i = 1; i <= t; i++) cout << "Case #" << i << ": ", solve();
}
