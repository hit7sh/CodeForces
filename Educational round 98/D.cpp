// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "(" << __LINE__ << ": "<< #x << " = " << x << ")\n"
 
#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )
 
using namespace std;
using mii = map<int, int>;
using pii = pair<int, int>;
 
using ll = int64_t;
 
const int mod = 998244353, mxN = 5e5+5, INF = 0x3f3f3f3f;
 
template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }
 
ll mod_pow(ll x, ll y){ll res=1;x%=mod;for(;y>0; y>>=1, x=(x*x)%mod)if(y&1) res=(res*x) % mod; return res; }ll mod_inv ( ll n ){ll ans = mod_pow ( n , mod - 2 ); return ans ;}inline ll mul(ll a, ll b){a%=mod, b%=mod;return (a*b)%mod;}ll sub(ll a,ll b){a%=mod, b%=mod;return (a-b+mod)%mod;}inline ll add(ll a, ll b){a%=mod, b%=mod; return (a+b)%mod;}
vl fib(mxN);


 
void solve() {
	ll n, i, j;
	cin >> n;
	print(mul(fib[n], mod_inv(mod_pow(2, n))));
}



int main() {
			#ifndef ONLINE_JUDGE
								freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
							#endif
	fib[1] = 1;
	for (int i = 2; i < mxN; i++)
		fib[i] = add(fib[i-1], fib[i-2]);

	__speed() solve();
}
