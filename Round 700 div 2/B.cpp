// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "(" << __LINE__ << ": "<< #x << " = " << x << ")\n"
 
#define Yes(x) print((x) ? "YES" : "NO")
#define tt 	int t; for (cin >> t; t--; )
 
#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define f1(i, n)  for (i = 1; i <=(int)(n); i++)
 
#define cmax(x, y) x = max(x, (y))
#define cmin(x, y) x = min(x, (y))
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
 
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

 
template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

 


 
void solve() {
		ll p, h, n, i;
	cin >> p >> h >> n;
	vector<pair<ll, ll>> M(n);
	f0(i, n) {
		cin >> M[i].F;
	}
	f0(i, n)cin >> M[i].S;
	sort(all(M));
	vl P(n), H(n);
	f0(i, n) P[i] = M[i].F, H[i] = M[i].S;
	
	f0(i, n) {
		if (h <= 0)
			break;
		ll req = H[i]/p + !!(H[i]%p), can = h/P[i] + !!(h%P[i]);
		
		if (can < req)
			break;
		h -= P[i]*req;
		H[i] -= p*req;
	}
	bool ok = 1;
	
	for (ll& x : H)
		ok &= x <= 0;
	Yes(ok);
}
 








 


int main() {
	__speed() tt solve();
}
