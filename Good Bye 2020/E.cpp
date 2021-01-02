// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n";
#define tt int t;for(cin>>t; t--; )
#define f0(i, n) for(i = 0; i < (int)(n); i++)
#define f1(i, n) for(i = 1; i<= (int)(n); i++)


using namespace std;
using ll = long long;
using vl = vector<ll>;
const int mod = 1e9+7,mxN = 1e6+5;

template<typename... Args>void print(Args... args){((cout << args << " "), ...); cout << endl;}
template<typename T>istream& operator>>(istream& in,vector<T> &a){for(auto&x:a)in>>x;return in;}
ll mod_pow(ll x, ll y){ll res=1;x%=mod;for(;y>0; y>>=1, x=(x*x)%mod)if(y&1) res=(res*x) % mod; return res; }ll mod_inv ( ll n ){ll ans = mod_pow ( n , mod - 2 ); return ans ;}inline ll mul(ll a, ll b){a%=mod, b%=mod;return (a*b)%mod;}ll sub(ll a,ll b){a%=mod, b%=mod;return (a-b+mod)%mod;}inline ll add(ll a, ll b){a%=mod, b%=mod; return (a+b)%mod;}

void solve(){//A
	ll m, n, i, j;
	cin >> n;
	vl A(n);
	cin >> A;
	vl bitcnt(60);
	for(ll x:A) {
		f0(i, 60) {
			if ((1LL<<i)&x)
				bitcnt[i] ++;
		}
	}
	ll ans=0;
	for(ll x:A) {
		ll ands=0, ors=0;
		f0(i, 60) {
			if((1LL<<i)&x) {
				ands = add(ands, mul((1LL<<i), bitcnt[i]));
				ors = add(ors, mul((1LL<<i), n));
			} else {
				ors = add(ors, mul((1LL<<i), bitcnt[i]));
			}
		}
		ans = add(ans, mul(ands, ors));
	}
	print(ans);
}

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    __speed() tt solve();
    return 0;
}
