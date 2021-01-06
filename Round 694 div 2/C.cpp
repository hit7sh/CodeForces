// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n";
#define tt int t;for(cin>>t; t--; )

#define f0(i, n) for(i = 0; i < (int)(n); i++)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x.size())



using namespace std;

using ll = long long;
using vi = vector<int>;

using vvi = vector<vi>;
using vl = vector<ll>;


template<typename... T> void print(T... args) { ((cout << args << " "), ...); cout << endl; }

template<typename T> istream& operator>>(istream& in,vector<T> &a) { for(auto&x:a)in>>x;return in; }
template<typename T> ostream& operator<<(ostream& out,vector<T> a) { for(auto&x:a)out << x << ' ';return out; }


void solve() {
	ll i, n, m;
	cin >> n >> m;

	vl K(n), C(m);
	cin >> K >> C;
	for(ll& x:K)x--;

	sort(rall(K));

	ll ans=0;
	f0(i, n) 
		ans += C[min(K[i], i)];

	print(ans);
}	

signed main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		
    __speed() tt solve();
    return 0;
}
