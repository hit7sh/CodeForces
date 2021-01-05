// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << __LINE__ << ": " << "[" << #x << " = " << x << " ]\n";
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
#define endl "\n"
#define S second
#define F first

using namespace std;
using mii = map<int, int>;
using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
const ll mod = 1e9+7,mxN = 1e7;

template<typename... Args>inline void print(Args... args){((cout << args << " "), ...); cout << endl;}
template<typename T>istream& operator>>(istream& in,vector<T> &a){for(auto&x:a)in>>x;return in;}

void solve() {//b
	int i, n;
	cin >> n;
	vi A(n);
	cin >> A;
	int mx=0;
	for(int& x:A)cmax(mx, x);
	ll ans=0;
	vl mem(n);
	for(i=n-1;i>=0;i--) {

		for(int j=i+A[i];j<n;j+=A[j]) {
			if(mem[j]==0)
				mem[i] += A[j];
			else {
				mem[i] += mem[j];
				break;
			}
		}
		mem[i] += A[i];
		cmax(ans, mem[i]);
	}
	
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
