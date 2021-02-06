// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "(" << __LINE__ << ": "<< #x << " = " << x << ")\n"
 
#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )
 
#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define f1(i, n)  for (i = 1; i <=(int)(n); i++)
 
 
using namespace std;
using mii = map<int, int>;
using pii = pair<int, int>;
 
using ll = int64_t;
using vi = vector<int>;
 
using vvi = vector<vi>;
using vl = vector<ll>;
 
 
template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot; }
 

 


 
void solve() {
	int n, i, m, j;
	cin >> n >> m;
	vi A(n), B(n), C(m);
	cin >> A >> B >> C;
	
	vvi wants(n+1), need(n+1);
	f0(i, n) {
		wants[B[i]].EB(i);
		if (A[i] != B[i])
			need[B[i]].EB(i);
	}
	bool ok = 1;
	if (wants[C.back()].empty()) {
		ok = 0;
	}
	vi where(m, -1);

	for (i = m - 1; ~i; --i) {
		if (!need[C[i]].empty()) {
			where[i] = need[C[i]].back() + 1;
			need[C[i]].pop_back();
		} else if (!wants[C[i]].empty()) {
			where[i] = 	wants[C[i]].back() + 1;
		} else {
			where[i] = where.back();
		}
	}
	for (i = 0; i <= n; i++) 
		if (!need[i].empty())
			ok = 0;

	if (!ok)
		print("NO");
	else
		print("YES", where);
}

 


int main() {

	__speed() tt solve();
}
