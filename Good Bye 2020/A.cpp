// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n";
#define tt int t;for(cin>>t; t--; )
#define f0(i, n) for(i = 0; i < (int)(n); i++)
#define f1(i, n) for(i = 1; i<= (int)(n); i++)


using namespace std;
using vi = vector<int>;


template<typename... Args>inline void print(Args... args){((cout << args << " "), ...); cout << endl;}
template<typename T>istream& operator>>(istream& in,vector<T> &a){for(auto&x:a)in>>x;return in;}

void solve(){//b
	int n, a, i, j;
	cin >> n;
	vi A(n);
	cin >> A;
	vi d(51);
	f0(i, n)
		f0(j, n)
			d[abs(A[i]-A[j])]++;
	int ans=0;
	f1(i, 50)
		ans += !!d[i];
	print(ans);
}

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    __speed() tt solve();
    return 0;
}
