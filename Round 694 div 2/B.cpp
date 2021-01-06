// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n";
#define tt int t;for(cin>>t; t--; )

#define f0(i, n) for(i = 0; i < (int)(n); i++)
#define f1(i, n) for(i = 1; i<= (int)(n); i++)

#define cmax(x, y) x=max(x, y);
#define cmin(x, y) x=min(x, y);

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x.size())

#define EB emplace_back
#define PB push_back


using namespace std;
using mii = map<int, int>;
using pii = pair<int, int>;

using ll = long long;
using vi = vector<int>;

using vvi = vector<vi>;
using vl = vector<ll>;


template<typename... Args> void print(Args... args) { ((cout << args << " "), ...); cout << endl; }


ll sm;
void pro(vl& A, int x, int lv=0) {
	int n = sz(A), i;

	vl copies;
	bool er=0;

	f0(i, n) {
		sm +=(pow(x, lv))*A[i];
		if(A[i]%x==0)
			copies.EB((A[i]/x));
		else{
			er=1;
			break;
		}
	}

	if(er) {
		for (i++; i<n; i++)
			sm +=(pow(x, lv))*A[i];
		for (ll& y:copies)
			sm +=(pow(x, lv+1))*y;

		return;
	}
	pro(copies, x, lv+1);
}

void solve() {
	int i, n, x;
	cin >> n >> x;
	vl A(n);
	cin >> A;
	sm=0;
	pro(A, x);
	print(sm);
}	

signed main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		
    __speed() tt solve();
    return 0;
}
