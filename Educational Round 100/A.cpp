// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define tt int t;for(cin>>t; t--; )
#define all(x) x.begin(), x.end()

using namespace std;
using mii = map<int, int>;
using ll = long long;
using vi = vector<int>;

template<typename... Args>void print(Args... args){((cout << args << " "), ...); cout << endl;}

void solve(){//A
	int i, n;
	vi A(3);
	int sm=0;
	f0(i, 3)cin >> A[i], sm+=A[i];
	sort(all(A));
	int mn=min({A[0], A[1], A[2]});
	int ac=(sm)/9;
	print(sm%9==0&&mn-ac>=0?"YES":"NO");
}

int32_t main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    __speed() tt solve();
    return 0;
}
