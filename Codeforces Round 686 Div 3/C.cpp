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

	/* #include <ext/pb_ds/assoc_container.hpp> 
	#include <ext/pb_ds/tree_policy.hpp> 
	using namespace __gnu_pbds; 
	#define iset tree<ll , null_type,less<ll>, rb_tree_tag, tree_order_statistics_node_update>
	#define iof order_of_key
	#define findat find_by_order */
	const int N=2e5+5;
	vector<int> A[N];
	void solve(){//H

		int n, i, x;
		cin >> n;
		
		vi nm(n+1);
		f1(i, n)
			cin >> nm[i], A[nm[i]].clear();
		
		n = unique(nm.begin(), nm.end())-nm.begin();
		nm.resize(n);
		n--;
		f1(i, n)
			A[nm[i]].PB(i);
		if(n==1){
			print(0);
			return;
		}
		int ans=INT_MAX;
		f1(i, n){
			int cans=A[nm[i]].size();
			if(A[nm[i]][0]==1&&A[nm[i]].back()==n)
				cans--;
			else if(A[nm[i]][0]!=1&&A[nm[i]].back()!=n)
				cans++;
			ans=min(ans, cans);

		}
		print(ans);
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
