// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n";
#define tt int t;for(cin>>t; t--; )
#define f0(i, n) for(i = 0; i < (int)(n); i++)
#define f1(i, n) for(i = 1; i<= (int)(n); i++)


using namespace std;
using ll = long long;
using vi = vector<int>;


template<typename... Args>void print(Args... args){((cout << args << " "), ...); cout << endl;}


void solve(){//D
	int n, i, u, v;
	cin >> n;
	vi adj[n+1];
	vi w(n+1);
	f1(i, n)cin >> w[i];
	f0(i, n-1){
		cin >> u >> v;
		adj[u].EB(v);
		adj[v].EB(u);
	}
	vi leaf(n+1);
	f1(i, n)
		if(adj[i].size()==1)
			leaf[i]=1;
	vector<array<int, 2>> nonleaf;
	f1(i, n)
		if(leaf[i]==0)
			nonleaf.PB({w[i], (int)adj[i].size()});
	sort(rall(nonleaf));
	ll sl=0, snl=0;
	f1(i, n)
		if(leaf[i])
			sl+=w[i];
	for(auto x:nonleaf)
		snl += x[0];
		

	ll c=0, cs=0;
	f1(i, n-1){
		cout << (0ll + sl + snl + cs) << ' ';
		// dbg(cs);
		if(!empty(nonleaf)){
		cs += nonleaf[c][0];
			nonleaf[c][1]--;
		if(nonleaf[c][1]==1)
			c++;
		
	}
	}
	cout << endl;
}

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    __speed() tt solve();
    return 0;
}
