// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << __LINE__ << ": " << "[" << #x << " = " << x << " ]\n";
#define tt int t;for(cin>>t; t--; )


using namespace std;

template<typename... Args>inline void print(Args... args){((cout << args << " "), ...); cout << endl;}
inline void Yes(bool e){cout << (e?"Yes\n":"No\n");}inline void yes(bool e){cout << (e?"yes\n":"no\n");}inline void YES(bool e){cout << (e?"YES\n":"NO\n");}

void solve() {
	int w, h, n;
	cin >> w >> h >> n;

	int a=0, b=0;
	while(w&1^1) {
		a ++;
		w/=2;
	}
	while(h&1^1) {
		b ++;
		h/=2;
	}
	YES(pow(2, a+b)>=n);
}	

signed main() {
		
    __speed() tt solve();
    return 0;
}
