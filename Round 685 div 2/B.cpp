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
#define rall(x) x.rbegin(), x.rend()
#define EB emplace_back
#define PB push_back
#define F first
#define S second
#define endl "\n"

using namespace std;
using mii = map<int, int>;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
const int mod = 1e9+7,mxN = 2e6+5;

template<typename... Args>void print(Args... args){((cout << args << " "), ...);cout << endl;}
ll mod_pow(ll x, ll y){ll res = 1;x = x % mod;while(y>0){if(y&1)res = (res*x) % mod; y = y>>1;x = (x*x) % mod; }return res; }ll mod_inv ( ll n ){ll ans = mod_pow ( n , mod - 2 ) ;return ans ;}ll mul(ll a, ll b){a%=mod, b%=mod;return (a*b)%mod;}ll sub(ll a,ll b){a%=mod, b%=mod;return (a-b+mod)%mod;}ll add(ll a, ll b){a%=mod, b%=mod;return (a+b)%mod;}
bool _prime(ll n){if(n<2)return 0;if(n<4)return 1;if(n%2==0||n%3==0)return 0;for(ll i=5;i*i<=n;i+=6)if(n%i==0||n%(i+2)==0)return 0;return 1;}


void solve(){//H
	string s;
	int q, l, r;
	cin >> q >> q;
	cin >> s;
	while(q--){
		cin >> l >> r;
		l--, r--;
		string t=s.substr(l, r-l+1);
		char tom=t[0];
		bool ok=0;
		for(int i=0;i<l;i++)
			if(s[i]==tom)
				ok=1;
		tom=t.back();
		for(int i=r+1;i<s.length();i++)
			if(s[i]==tom)
				ok=1;
		print(ok?"YES":"NO");
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	#endif
    __speed();
    tt solve();
    return 0;
}
