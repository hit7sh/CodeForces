// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define tt int t;for(cin>>t; t--; )
#define f0(i, n) for(i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
#define EB emplace_back
#define endl "\n"


using namespace std;
using vi = vector<int>;

template<typename... Args>void print(Args... args){((cout << args << " "), ...);cout << endl;}


void solve(){
	int n, i;
	cin >> n;
	vector<array<int, 2>> pts(n);
	f0(i, n)
		cin >> pts[i][0] >> pts[i][1];
	vi L(n), R(n);
	f0(i, n)
		L.EB(pts[i][0]), R.EB(pts[i][1]);
	sort(all(L));
	sort(all(R));
	int ans=INT_MAX;
	f0(i, n){
		int remove_cnt = lower_bound(all(R), pts[i][0])-R.begin();
		remove_cnt += n-(upper_bound(all(L), pts[i][1])-L.begin());
		ans = min(ans, remove_cnt);
	}
	print(ans);
}

int32_t main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    __speed() tt solve();
    return 0;
}
