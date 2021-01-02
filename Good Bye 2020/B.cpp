// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n";
#define tt int t;for(cin>>t; t--; )
#define f0(i, n) for(i = 0; i < (int)(n); i++)


using namespace std;
using mii = map<int, int>;
using vi = vector<int>;


template<typename... Args>inline void print(Args... args){((cout << args << " "), ...); cout << endl;}
template<typename T>istream& operator>>(istream& in,vector<T> &a){for(auto&x:a)in>>x;return in;}

ll fact[51];
void solve(){//b
	int n, a, i, j;
	cin >> n;
	vi A(n);
	cin >> A;
	map<int, int>m;
	f0(i, n){
		if(m.count(A[i]))
			A[i]++;
		m[A[i]]++;
	}
	print(m.size());
}

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fact[0]=1;
	for(ll i=1;i<=50;i++)
		fact[i] = mul(i, fact[i-1]);
    __speed() tt solve();
    return 0;
}
