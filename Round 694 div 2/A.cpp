// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n";
#define tt int t;for(cin>>t; t--; )


using namespace std;
using ll = long long;


template<typename... Args> void print(Args... args) { ((cout << args << " "), ...); cout << endl; }


void solve() {
	int i, n, x;
	cin >> n >> x;
	vi A(n);
	cin >> A;
	ll mn=0, mx=0;
	for(int y:A)
		mn += (y+x-1)/x, mx +=y;
	print((mx+x-1)/x, mn);
}	

signed main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		
    __speed() tt solve();
    return 0;
}
