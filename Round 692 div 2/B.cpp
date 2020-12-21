// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define tt int t;for(cin>>t; t--; )


using namespace std;
using mii = map<int, int>;
using pii = pair<int, int>;
using ll = long long;


bool chk(ll n){
	for(ll t=n;t;t/=10)
		if(t%10 && n%(t%10))
			return 0;
	return 1;
}
void solve(){//A
	ll n, m, i;
	cin >> n;
	while(!chk(n))n++;
	print(n);
}
signed main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    __speed() tt solve();
    return 0;
}
