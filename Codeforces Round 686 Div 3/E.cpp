// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "--- " << #x << " = " << x << " ---\n";
#define findmax(v) *max_element(v.begin(), v.end())
#define _sum(a) accumulate(a.begin(), a.end(), 0)
#define tt int t;for(cin>>t; t--; )
#define f0(i, n) for(i = 0; i < int(n); i++)
#define f1(i, n) for(i = 1; i<= int(n); i++)
#define all(x) x.begin(), x.end()
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
const int mod = 1e9+7,mxN = 2e5+5;

template<typename... Args>void print(Args... args){((cout << args << " "), ...);cout << endl;}
ll mod_pow(ll x, ll y){ll res = 1;x = x % mod;while(y>0){if(y&1)res = (res*x) % mod; y = y>>1;x = (x*x) % mod; }return res; }ll mod_inv ( ll n ){ll ans = mod_pow ( n , mod - 2 ) ;return ans ;}ll mul(ll a, ll b){a%=mod, b%=mod;return (a*b)%mod;}ll sub(ll a,ll b){a%=mod, b%=mod;return (a-b+mod)%mod;}ll add(ll a, ll b){a%=mod, b%=mod;return (a+b)%mod;}
bool _prime(ll n){if(n<2)return 0;if(n<4)return 1;if(n%2==0||n%3==0)return 0;for(ll i=5;i*i<=n;i+=6)if(n%i==0||n%(i+2)==0)return 0;return 1;}

/* #include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define iset tree<ll , null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define iof order_of_key
#define findat find_by_order */
int i, n, x, endnode, start;
vi adj[mxN];
int vis[mxN], vis2[mxN];
int prv[mxN];
bool dfs(int node, int par)
{
	vis[node]=1;

	for(int child:adj[node])
	{
		if(!vis[child])
		{
			prv[child]=node;
			if(dfs(child, node))
				return true;
		}
		else if(child!=par)
			{prv[child]=node,endnode=par, start=child;return true;}
	}
	return false;
}
int a, b, c;
void dfs1(int u){
	vis2[u]=1;
	c++;
	for(int x:adj[u]){
		if(x!=a&&x!=b&&!vis2[x]){
			dfs1(x);
		}
	}
}
void solve(){
	cin >> n;
	int u, v;
	f0(i, n)
		adj[i].clear(), vis[i]=vis2[i]=0, prv[i]=0;
	prv[0]=-1;
	f0(i, n)
		cin >> u >> v, u--, v--, adj[u].PB(v), adj[v].PB(u);
	dfs(0, -1);

	vi cycle;
	while(true){
		cycle.PB(endnode);
		endnode=prv[endnode];
		if(cycle.size()>1&&cycle[0]==cycle.back())
			break;
	}
	cycle.pop_back();
	int l=cycle.size();ll ans=0;
	f0(i, l){
		a=(i-1)==-1?(l-1):i-1;
		a=cycle[a];
		b=(i+1)==l?(0):i+1;
		b=cycle[b];
		c=0;
		int j;
		dfs1(cycle[i]);
		
		ans += (1ll*c*(c-1))/2 + 1ll*(n-c)*c;
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
