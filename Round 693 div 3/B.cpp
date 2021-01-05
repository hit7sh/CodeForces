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


template<typename... Args>inline void print(Args... args){((cout << args << " "), ...); cout << endl;}
inline void Yes(bool e){cout << (e?"Yes\n":"No\n");}inline void yes(bool e){cout << (e?"yes\n":"no\n");}inline void YES(bool e){cout << (e?"YES\n":"NO\n");}


void solve() {//b
	int i, n;
	cin >> n;
	vi A(n);
	cin >> A;
	sort(all(A));
	int sum=0, c[3]={};
	f0(i, n) sum+=A[i],c[A[i]]++;
	if(sum&1){
		print("NO");return;
	}
	if(c[2]==0){
		YES(1);
		return;
	}
	sum /= 2;
	int al=0;
	int req2 = sum/2;
	al = 2*min(req2, c[2]);
	int rem = sum-al;
	YES(c[1]>=rem);
}	

signed main() {

    __speed() tt solve();
    return 0;
}
