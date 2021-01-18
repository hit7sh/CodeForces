// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define tt 	int t; for (cin >> t; t--; )

#define f0(i, n)  for (i = 0; i < (int)(n); i++)

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())

#define EB emplace_back




using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }







void solve() {
	int n, m, u, v, i, j;
    cin >> n >> m;
    
    vvi adj(n);
    
    f0(i, m) { 
    	cin >> u >> v;
    	--u, --v;
    	adj[u].EB(v);
    	adj[v].EB(u);
    }
    
	vi inc(n, -1), que;
	inc[0] = 1;
  
	for (int x:adj[0])
		que.EB(x), inc[x] = 0;

	for (i = 0; i < sz(que); i++) {
		for (int x:adj[que[i]]) {
			if (inc[x] == -1) {
				 inc[x] = 1;
				 for (int y:adj[x]) {
				 	if (inc[y] == -1)
				 		inc[y] = 0;
				 		que.EB(y);
				 }
			}
		}
	}

	if (*min_element(all(inc)) == -1)
		print("NO");
	else {
		print("YES");
		print(count_if(all(inc), [](int x){return x==1;}));
		f0(i, n)
			if(inc[i] == 1)
				cout << i+1 << ' ';
		cout << endl;
	}    
}






int main() {
    __speed() tt solve();

    return 0;
}
