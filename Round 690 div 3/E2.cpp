// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "--- " << #x << " = " << x << " ---\n";
#define findmax(v) *max_element(v.begin(), v.end())
#define _sum(a) accumulate(a.begin(), a.end(), 0)
#define tt int t;for(cin>>t; t--; )
#define f0(i, n) for(i = 0; i < (int)(n); i++)
#define f1(i, n) for(i = 1; i<= (int)(n); i++)
#define all(x) x.begin(), x.end()
#define pq priority_queue
#define EB emplace_back
#define PB push_back
#define endl "\n"
#define S second
#define ar array
#define F first

using namespace std;
// using mii = map<int, int>;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
const int mod = 1e9+7,mxN = 1e6+5;

template<typename... Args>void print(Args... args){((cout << args << " "), ...);
cout << endl;}
ll mod_pow(ll x, ll y){ll res=1;x%=mod;for(;y>0; y>>=1, x=(x*x)%mod)if(y&1)
res=(res*x) % mod; return res; }ll mod_inv ( ll n ){ll ans = mod_pow ( n , mod - 2 );
return ans ;}ll mul(ll a, ll b){a%=mod, b%=mod;return (a*b)%mod;}ll sub(ll a,ll b){
a%=mod, b%=mod;return (a-b+mod)%mod;}ll add(ll a, ll b){a%=mod, b%=mod;
return (a+b)%mod;}


ll A[mxN], n, m, i, j, k, fact[mxN];
ll C(ll n, ll r){
	if(r<0 or r>n)
		return 0;
	return mul(fact[n], mul(mod_inv(fact[n-r]), mod_inv(fact[r])));
}
void solve(){//A
	cin >> n >> m >> k;
	f0(i, n)
		cin >> A[i];
	ll ans=0;
	sort(A, A+n);
	f0(i, n){
		ll lb=lower_bound(A, A+n, A[i]+k+1)-A;
		
		ll g=lb-1-i;
		if(g>=m-1)
			ans = add(ans, C(g, m-1));

	}
	print(ans);

}

int32_t main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    __speed();
    fact[0]=1;
    for(int i=1;i<mxN;i++)
    	fact[i] = mul(i,fact[i-1]);
    tt solve();
    return 0;
}
