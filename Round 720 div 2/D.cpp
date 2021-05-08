#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100005];
vector<vector<int>>ans;
int dfs(int u, int par) {
	int ch=0,nxt=u;
	for(int& v : adj[u]) if(v^par) {
		int endv=dfs(v,u);
		if(endv < 0) continue;
		ch++;
		if(ch==1) nxt=endv;
		else if(ch==2) ans.push_back({par, u, nxt, endv}),nxt=-1;
		else ans.push_back({u,v,v,endv});
	}
	return nxt;
}

int main() {
	int i,to, n;
	for(cin>>n;cin>>n;ans.clear()){
		for(int j=1,x,y;j<n;j++) {
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(i=1;;i++) if(adj[i].size()==1) break;
		to=dfs(i,-1);
		cout<<ans.size()<<endl;
		for(auto& x:ans) cout<<x[0]<<" "<<x[1]<<" "<<to<<" "<<x[2]<<endl,to=x[3];
		for(i=1;i<=n;i++) adj[i].clear();
	}
	return 0;
}
